#include "PmergeMe.hpp"
#include <cstddef>
#include <iostream>
#include <iterator>
#include <sys/time.h>
#include <algorithm>
#include <sstream>

// Default constructor - initializes comparison counters to 0
PmergeMe::PmergeMe() : _compareVec(0), _compareDeq(0)
{}

// Copy constructor - creates deep copy, resets counters for fair comparison
PmergeMe::PmergeMe(const PmergeMe& other) : _nbrVec(other._nbrVec), _compareVec(0),
			_durationVec(0),  _compareDeq(0), _durationDeq(0)
{}

// Copy assignment operator
PmergeMe& PmergeMe::operator=(const PmergeMe& other) 
{
	if (this != &other)
	{
		_nbrVec = other._nbrVec;
		_compareVec = other._compareVec;
		_compareDeq = other._compareDeq;
		_durationVec = other._durationVec;
		_durationDeq = other._durationDeq;
	}
	return *this;
}

// Destructor - nothing to clean up
PmergeMe::~PmergeMe()
{}

// Main entry point: parses input, sorts using both vector and deque,
// prints results and timing information
void PmergeMe::runPrint(int ac, char **av)
{
	// Parse and sort with vector
	if (parseVector(ac, av)) 
		return ;
	processVec();
	
	// Parse and sort with deque (re-parsing since parseVector consumed the args)
	if (parseDeque(ac, av))
		return ;
	processDeq();
	
	// Print input and output arrays
	std::cout << "Before: "; printVector(_nbrVec);
	std::cout << "After: "; printVector(_sortedVec);
	
	// Print timing for both containers
	std::cout << "Time to process a range of " << _nbrVec.size() << " elements with std::vector : " << _durationVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _nbrDeq.size() << " elements with std::deque : " << _durationDeq << " us" << std::endl;
}

// Parse CLI arguments into vector of integers
// Handles single string with multiple numbers or multiple arguments
int PmergeMe::parseVector(int ac,  char **av)
{
	// No arguments provided
	if (ac == 1)
	{
		printErr("No Input");
		return 1;
	}
	// Single argument - could be space-separated numbers
	else if (ac == 2)
	{
		std::stringstream ss(av[1]);
		std::string tmp;

		// Parse each space-separated value
		while (ss >> tmp)
		{
			if (!strdigit(tmp.c_str()))
			{
				printErr("Wrong Input");
				return 1;
			}
			_nbrVec.push_back(atoi(tmp.c_str()));
		}
		// Print single element directly
		// if (_nbrVec.size() == 1)
		// 	std::cout << _nbrVec[0] << std::endl;
	}
	// Multiple arguments - each is a number
	else
	{
		for (int i = 1; av[i]; i++)
		{
			if (!strdigit(av[i]))
			{
				printErr("Wrong Input");
				return 1; 
			}
			else
				_nbrVec.push_back(atoi(av[i]));
		}
	}
	return 0;
}

// Main vector sorting function using Ford-Johnson algorithm
// Records execution time using gettimeofday
void PmergeMe::processVec()
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	
	// Generate Jacobsthal numbers for insertion order
	makeJacobVec();
	
	// Create initial chain from input numbers
	chainVec number;
	chainVec sorted;
	for (size_t i = 0; i < _nbrVec.size(); i++)
	{
		ChainV c;
		c.winner = _nbrVec[i];
		number.push_back(c);
	}
	
	// Recursively sort using merge-insertion algorithm
	sorted = recurse(number);
	
	// Extract sorted values from chain structure
	for (size_t i = 0; i < sorted.size(); i++)
		_sortedVec.push_back(sorted[i].winner);
	
	// Calculate duration in microseconds
	gettimeofday(&end, NULL);
	long startUsec	= (start.tv_sec * 1000000) + start.tv_usec;
	long endUsec	= (end.tv_sec * 1000000) + end.tv_usec;
	_durationVec	= endUsec - startUsec;
}

// Generate Jacobsthal numbers: 3, 5, 11, 21, 43, 85, ...
// Formula: J(n) = J(n-1) + 2*J(n-2)
// Used to determine optimal insertion order in merge-insertion sort
// Limit of 10923 handles up to 3000 elements
void PmergeMe::makeJacobVec()
{
	_jacobVec.clear();
	_jacobVec.push_back(3);
	_jacobVec.push_back(5);
	
	int nbr = 0;
	while (_jacobVec.back() < 10923)
	{
		nbr = _jacobVec.back() + (2 * _jacobVec[_jacobVec.size() - 2]);
		_jacobVec.push_back(nbr);
	}
	return ;
}

// Validate that string represents a valid integer (allow optional leading +)
// Returns 1 for valid integer, 0 for invalid
int	PmergeMe::strdigit(const char* str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			// Allow + sign at start if followed by digit
			if (!(i == 0 && str[i] == '+' && std::isdigit(str[i + 1])))
				return 0;
	}
	return 1;
}

// Recursive merge-insertion sort implementation
// Base case: single element is already sorted
// Recursively: pair elements, sort pairs, then merge
chainVec	PmergeMe::recurse(chainVec tmp)
{
	// Base case: 0 or 1 element is sorted
	if (tmp.size() <= 1)
		return tmp;

	// Check if there's an odd element (unpaired)
	bool		hasOdd = (tmp.size() % 2 != 0);
	ChainV		oddChain;
	
	// Step 1: Create new level by pairing and comparing
	// Each pair produces a winner and loser
	chainVec newLvl = createNewLvl(tmp, hasOdd, oddChain);

	// Step 2: Recursively sort the winners
	newLvl = recurse(newLvl);

	// Step 3: Prepare main chain and pending elements for insertion
	chainVec	main;
	chainVec	pending;
	
	preJacob(newLvl, main, pending, hasOdd, oddChain);
	
	// Step 4: Insert pending elements using Jacobsthal order
	insertJacob(main, pending);
	
	return main;
}

// Create new level by comparing pairs of elements
// In each pair: larger becomes winner, smaller becomes loser
// Handles odd element by removing it before processing
chainVec	PmergeMe::createNewLvl(chainVec& tmp, bool& hasOdd, ChainV& oddChain)
{
	chainVec	newLvl;

	// Handle odd element - save and remove from processing
	if (hasOdd)
	{
		oddChain = tmp.back();
		tmp.pop_back();
	}
	
	// Process each pair: compare and determine winner/loser
	for (size_t i = 0; i < tmp.size(); i += 2)
	{
		_compareVec++;
		// Winner is larger element, loser is smaller
		if (tmp[i].winner > tmp[i + 1].winner)
		{
			tmp[i].losers.push_back(tmp[i + 1]);
			newLvl.push_back(tmp[i]);
		}
		else 
		{
			tmp[i + 1].losers.push_back(tmp[i]);
			newLvl.push_back(tmp[i + 1]);
		}
	}
	return newLvl;
}

// Prepare for Jacobsthal insertion phase
// Separates main chain (winners) from pending chain (losers)
// Main contains first element of each pair, pending contains losers
void	PmergeMe::preJacob(chainVec& newLvl, chainVec& main, chainVec& pending, bool hasOdd, ChainV& oddChain)
{
	for (size_t i = 0; i < newLvl.size(); i++)
	{
		// Take last loser from each winner's chain
		pending.push_back(newLvl[i].losers.back());
		// Record position in main chain
		pending[i].pos = i;
		newLvl[i].losers.pop_back();
		// Add winner to main chain
		main.push_back(newLvl[i]);
	}
	// Add odd element to pending if exists
	if (hasOdd)
	{
		oddChain.pos = main.size();
		pending.push_back(oddChain);
	}
}

// Insert pending elements using Jacobsthal number order
// Uses binary search (lower_bound) within bounds for efficient insertion
// Updates positions of all pending elements after each insertion
void	PmergeMe::insertJacob(chainVec& main, chainVec& pending)
{
	// Insert first pending element at beginning
	if (!pending.empty())
	{
		main.insert(main.begin(), pending[0]);
		updatePos(pending, 0);
	}

	size_t		lastInsertedPos = 1;
	ComparatorV	comp(_compareVec);

	// Process Jacobsthal numbers in order
	for (size_t i = 0; i < _jacobVec.size(); i++)
	{
		size_t	jacobNo = _jacobVec[i];
		size_t	currLimit = std::min<size_t>(jacobNo, pending.size());
		
		// Insert elements from currLimit down to lastInsertedPos
		for (size_t j = currLimit; j > lastInsertedPos; j--)
		{
			ChainV				target	  = pending[j - 1];
			chainVec::iterator	limit	  = main.begin() + pending[j - 1].pos;
			// Binary search within valid range
			chainVec::iterator	insertLoc = std::lower_bound(main.begin(), limit, target.winner, comp);

			size_t	insertIdx = std::distance(main.begin(), insertLoc);
			main.insert(insertLoc, target);
			// Update positions of all pending elements
			updatePos(pending, insertIdx);
		}
		lastInsertedPos = currLimit;

		if (lastInsertedPos == pending.size())
			break ;
	}
}

// Update positions of all pending elements after an insertion
// Elements at or after insertion point need their position incremented
void PmergeMe::updatePos(chainVec& pending, size_t insertIdx)
{
	for (size_t k = 0; k < pending.size(); k++)
		if (pending[k].pos >= insertIdx)
			pending[k].pos++;
}

// Print vector elements space-separated
void PmergeMe::printVector(const std::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

// Parse CLI arguments into deque (same logic as parseVector)
int PmergeMe::parseDeque(int ac, char **av)
{
	if (ac == 1)
	{
		printErr("No Input");
		return 1;
	}
	else if (ac == 2)
	{
		std::stringstream ss(av[1]);
		std::string tmp;

		while (ss >> tmp)
		{
			if (!strdigit(tmp.c_str()))
			{
				printErr("Wrong Input");
				return 1;
			}
			_nbrDeq.push_back(atoi(tmp.c_str()));
		}
		if (_nbrDeq.size() == 1)
			std::cout << _nbrDeq[0] << std::endl;
	}
	else
	{
		for (int i = 1; av[i]; i++)
		{
			if (!strdigit(av[i]))
			{
				printErr("Wrong Input");
				return 1;
			}
			else
				_nbrDeq.push_back(atoi(av[i]));
		}
	}
	return 0;
}

// Main deque sorting function (identical logic to processVec)
void PmergeMe::processDeq()
{
	struct timeval start, end;
	
	gettimeofday(&start, NULL);
	
	makeJacobDeq();
	chainDeq number;
	chainDeq sorted;
	for (size_t i = 0; i < _nbrDeq.size(); i++)
	{
		ChainD c;
		c.winner = _nbrDeq[i];
		number.push_back(c);
	}
	sorted = recurse(number);
	for (size_t i = 0; i < sorted.size(); i++)
		_sortedDeq.push_back(sorted[i].winner);
	
	gettimeofday(&end, NULL);
	long startUsec	= (start.tv_sec * 1000000) + start.tv_usec;
	long endUsec	= (end.tv_sec * 1000000) + end.tv_usec;
	_durationDeq	= endUsec - startUsec;
}

// Generate Jacobsthal numbers for deque (identical to makeJacobVec)
void PmergeMe::makeJacobDeq()
{
	_jacobDeq.clear();
	_jacobDeq.push_back(3);
	_jacobDeq.push_back(5);
	
	int nbr = 0;
	while (_jacobDeq.back() < 10923)
	{
		nbr = _jacobDeq.back() + (2 * _jacobDeq[_jacobDeq.size() - 2]);
		_jacobDeq.push_back(nbr);
	}
	return ;
}

// Recursive merge-insertion sort for deque (identical to recurse)
chainDeq	PmergeMe::recurse(chainDeq tmp)
{
	if (tmp.size() <= 1)
		return tmp;
	
	bool		hasOdd = (tmp.size() % 2 != 0);
	ChainD		oddChain;
	chainDeq	newLvl = createNewLvl(tmp, hasOdd, oddChain);

	newLvl =  recurse(newLvl);

	chainDeq	main;
	chainDeq	pending;

	preJacob(newLvl,  main,  pending,  hasOdd, oddChain);
	insertJacob(main, pending);

	return main;
}

// Create new level for deque (identical to createNewLvl)
chainDeq	PmergeMe::createNewLvl(chainDeq& tmp, bool& hasOdd, ChainD& oddChain)
{
	chainDeq	newLvl;

	if (hasOdd)
	{
		oddChain = tmp.back();
		tmp.pop_back();
	}
	for (size_t i = 0; i < tmp.size(); i += 2)
	{
		_compareDeq++;
		if (tmp[i].winner > tmp[i + 1].winner)
		{
			tmp[i].losers.push_back(tmp[i + 1]);
			newLvl.push_back(tmp[i]);
		}
		else 
		{
			tmp[i + 1].losers.push_back(tmp[i]);
			newLvl.push_back(tmp[i +  1]);
		}
	}
	return newLvl;
}

// Prepare for Jacobsthal insertion for deque (identical to preJacob)
void	PmergeMe::preJacob(chainDeq& newLvl, chainDeq& main, chainDeq& pending, bool hasOdd, ChainD& oddChain)
{
	for (size_t i = 0; i < newLvl.size(); i++)
	{
		pending.push_back(newLvl[i].losers.back());
		pending[i].pos = i;
		newLvl[i].losers.pop_back();
		main.push_back(newLvl[i]);
	}
	if (hasOdd)
	{
		oddChain.pos = main.size();
		pending.push_back(oddChain);
	}
}

// Insert pending elements using Jacobsthal order for deque
void	PmergeMe::insertJacob(chainDeq& main, chainDeq& pending)
{
	if (!pending.empty())
	{
		main.insert(main.begin(), pending[0]);
		updatePos(pending, 0);
	}
	size_t		lastInsertedPos = 1;
	ComparatorD	comp(_compareDeq);

	for (size_t i = 0; i < _jacobDeq.size(); i++)
	{
		size_t	jacobNo = _jacobDeq[i];
		size_t	currLimit = std::min<size_t>(jacobNo, pending.size());

		for (size_t j = currLimit; j > lastInsertedPos; j--)
		{
			ChainD				target	  = pending[j - 1];
			chainDeq::iterator	limit	  = main.begin() + pending[j - 1].pos;
			chainDeq::iterator	insertLoc = std::lower_bound(main.begin(), limit, target.winner, comp);
			size_t				insertIdx = std::distance(main.begin(), insertLoc);
			main.insert(insertLoc, target);
			updatePos(pending,insertIdx);
		}
		lastInsertedPos =  currLimit;
		if (lastInsertedPos ==  pending.size())
			break ;
	}
}

// Update positions for deque pending elements
void	PmergeMe::updatePos(chainDeq& pending, size_t insertIdx)
{
	for (size_t k = 0; k < pending.size(); k++)
		if (pending[k].pos >= insertIdx)
			pending[k].pos++;
}

// Print error message to stderr
void	PmergeMe::printErr(std::string str)
{
	std::cerr << "Error: " << str << std::endl;
}

// Print deque elements space-separated
void PmergeMe::printDeque(const std::deque<int>& deq)
{
	for (size_t i = 0; i < deq.size(); ++i)
	{
		std::cout << deq[i];
		std::cout << " ";
	}
	std::cout << std::endl;
}
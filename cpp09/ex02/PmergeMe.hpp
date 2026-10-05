#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

// ChainV: Node for vector-based merge-insertion sort
// winner: the larger element in each pair comparison
// losers: elements that lost to this winner
// pos: current position in main chain (for insertion tracking)
struct ChainV
{
	int					winner;
	std::vector<ChainV>	losers;
	size_t				pos;
};

// ComparatorV: custom comparator for binary search with comparison counting
// Tracks number of comparisons made during insertion phase
struct ComparatorV
{
	size_t &count;

	ComparatorV(size_t& compareVec) : count(compareVec) {}

	// Returns true if other.winner < targetValue (increments comparison count)
	bool operator()(const ChainV& other, int targetValue) const
	{
		count++;
		return other.winner < targetValue;
	}
};

// ChainD: Same as ChainV but for std::deque container
struct ChainD
{
	int					winner;
	std::deque<ChainD>	losers;
	size_t				pos;
};

// ComparatorD: comparator for deque with comparison counting
struct ComparatorD
{
	size_t &count;

	ComparatorD(size_t& compareDeq) : count(compareDeq) {}

	bool operator()(const ChainD& other, int targetValue) const
	{
		count++;
		return other.winner < targetValue;
	}
};

typedef std::vector<ChainV> chainVec;
typedef std::deque<ChainD>  chainDeq;

class PmergeMe {
	private:
	//			VECTOR
		std::vector<int>	_nbrVec; // store the number
		std::vector<int>	_jacobVec;  // stores the Jacobsthal sequence values used to decide the insertion order during Ford-Johnson sorting.
		std::vector<int>	_sortedVec;
		size_t				_compareVec; // counts how many comparisons the vector version makes while inserting elements
		double				_durationVec; // how long microsecond

	//			DEQUE
		std::deque<int>		_nbrDeq;
		std::deque<int>		_jacobDeq;
		std::deque<int>		_sortedDeq;
		size_t				_compareDeq;
		double				_durationDeq;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		int		strdigit(const char* str);
		void	runPrint(int ac, char **av);
		void	printErr(std::string str);

		//				VECTOR
		int			parseVector(int ac, char **av);
		void		processVec();
		void		makeJacobVec();
		chainVec	recurse(chainVec tmp);
		chainVec	createNewLvl(chainVec& tmp, bool& hasOdd, ChainV& oddChain);
		void		preJacob(chainVec& newLvl, chainVec& main, chainVec& pending, bool hasOdd, ChainV& oddChain);
		void		insertJacob(chainVec& main, chainVec& pending);
		void		updatePos(chainVec& pending, size_t insertIdx);
		void		printVector(const std::vector<int>& vec);

		//				DEQUE
		int			parseDeque(int ac,  char **av);
		void		processDeq();
		void		makeJacobDeq();
		chainDeq	recurse(chainDeq tmp);
		chainDeq	createNewLvl(chainDeq& tmp, bool& hasOdd, ChainD& oddChain);
		void		preJacob(chainDeq& newLvl, chainDeq& main, chainDeq& pending, bool hasOdd, ChainD& oddChain);
		void		insertJacob(chainDeq& main, chainDeq& pending);
		void		updatePos(chainDeq& pending, size_t insertIdx);
		void		printDeque(const std::deque<int>& deq);
	};

#endif
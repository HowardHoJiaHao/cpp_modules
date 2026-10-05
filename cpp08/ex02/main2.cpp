

#include <iostream>
#include <algorithm>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    // 1. Test Standard Stack Operations
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size after one pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // 2. Test Iteration (The "Mutant" part)
    // In C++98, the type is: typename std::stack<int>::container_type::iterator
    MutantStack<int>::container_type::iterator it = mstack.begin();
    MutantStack<int>::container_type::iterator ite = mstack.end();

    std::cout << "\nIterating through MutantStack:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // 3. Test Compatibility with Standard Algorithms
    std::cout << "\nFinding 737 using std::find:" << std::endl;
    MutantStack<int>::container_type::iterator found = std::find(mstack.begin(), mstack.end(), 737);
    if (found != mstack.end())
        std::cout << "Found: " << *found << std::endl;

    // 4. Test Copy Constructor and Assignment
    std::stack<int> s(mstack);
    std::cout << "\nCopied to std::stack. Size: " << s.size() << std::endl;

    return 0;
}
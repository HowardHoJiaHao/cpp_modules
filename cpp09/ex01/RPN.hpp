#include <string>
#include <stack>
#include <list>

class RPN {
private:
	// stack only can first in first out which is safer thn use list 
	// which can take the int from middle or front 
	// Only exposes push(), pop(), top(), empty(), size()
	std::stack<int, std::list<int> > _nbr;
	std::string	_str;
public:
	RPN(std::string str);
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();
	void	runInput();
	int		checkOperator(char c);
	int		handleOperator(int i);
};
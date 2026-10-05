#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap nameless;
	ClapTrap Jack("Jack");
	ClapTrap flying("flying");
    
    std::cout << "---------------------------" << std::endl;
	Jack.attack("flying");
	Jack.takeDamage(3);
	Jack.beRepaired(2);
    
    std::cout << "---------------------------" << std::endl;

	ClapTrap CopyJack(Jack);
	CopyJack.attack("Nobody");

    std::cout << "---------------------------" << std::endl;

	ClapTrap Another("RandomGuy");
	Another = flying;
	Another.attack("Trump");

    std::cout << "---------------------------" << std::endl;

	Jack.takeDamage(999);
	Jack.attack("Flying_dutchman");
	Jack.beRepaired(1);

	return 0;
}
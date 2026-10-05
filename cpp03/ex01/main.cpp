
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (void)
{
	ClapTrap c1("Bob");
	c1.attack("Target Dummy");
	c1.takeDamage(5);
	c1.beRepaired(3);

	std::cout << " ---------------------------- " << std::endl;

	ScavTrap s1("Rex");
	s1.attack("Intruder");
	s1.takeDamage(100);
	s1.beRepaired(10);
	s1.guardGate();

	std::cout << " ---------------------------- " << std::endl;

	ScavTrap s2(s1);
	s2.attack("CloneTarget");

	std::cout << " ---------------------------- " << std::endl;

	ScavTrap s3("random Guy");
	s3 = s1;
	s3.guardGate();

	return 0;
}
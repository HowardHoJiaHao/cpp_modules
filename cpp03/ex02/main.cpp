
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main (void)
{
	ClapTrap c1("Bob");
	c1.attack("Target Dummy");
	c1.takeDamage(5);
	c1.beRepaired(3);

	std::cout << " ---------------------------- " << std::endl;

	FragTrap s1("Rex");
	s1.attack("Intruder");
	s1.takeDamage(20);
	s1.beRepaired(10);
	s1.highFivesGuys();

	std::cout << " ---------------------------- " << std::endl;

	FragTrap s2(s1);
	s2.attack("CloneTarget");

	std::cout << " ---------------------------- " << std::endl;

	FragTrap s3("random Guy");
	s3 = s1;
	s3.highFivesGuys();

	return 0;
}
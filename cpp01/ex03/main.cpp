#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main ()
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club); //with reference
		bob.attack();
		club.setType("some other type of club");	
		bob.attack();

	}
	{
		Weapon club = Weapon("crude spiked club");
		std::cout << "\n now is jim's turn \n" << std::endl;
		
		HumanB jim("Jim"); //this is special because it was not initialize with weapon
		jim.setWeapon(club); 
		jim.attack();
		club.setType("some most powerful type of club");
		jim.attack();
	}
	return 0;
}
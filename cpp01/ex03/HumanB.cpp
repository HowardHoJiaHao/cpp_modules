#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string Name):name(Name), weapon(NULL)
{}

void HumanB::setWeapon(Weapon &Weapon)
{
    this->weapon = &Weapon;
    std::cout << this->name << " set weapon to " << Weapon.getType() << std::endl; 
}

void HumanB::attack(void)
{
    if (!weapon)
    {
        std::cout << this->name << " has no weapon "<< std::endl;
        return;
    }
    std::cout << this->name << " attack with their " << this->weapon->getType() << std::endl;
}
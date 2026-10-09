#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string Name, Weapon &Weapon):name(Name), weapon(Weapon)
{}

void HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
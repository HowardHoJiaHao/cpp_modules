#include "Weapon.hpp"

Weapon::Weapon(std::string Type):type(Type)
{
    std::cout << "A Weapon " << Type << " is created." << std::endl;
}

const std::string& Weapon::getType(void) const
{
    return (this->type);
}

void Weapon::setType(std::string Type)
{
    this->type = Type;
    std::cout << "New Weapon " << Type << " is updated." << std::endl;
}

#include "Zombie.hpp"

Zombie::Zombie() : name("") {}

Zombie::Zombie(std::string Name) : name(Name) {}

Zombie::~Zombie(void)
{
    std::cout << this->name << " zombie destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string Name)
{
    this->name = Name;
}

std::string Zombie::getName()
{
    return (this->name);
}


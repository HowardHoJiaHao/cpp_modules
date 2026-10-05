#include "Zombie.hpp"

Zombie::Zombie(std::string Name) : name(Name) {}

Zombie::~Zombie(void)
{
    std::cout << this->name << " zombie destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name)
{
    return new Zombie(name);
}

void randomChump(std::string name)
{
    Zombie z(name);
    z.announce();
}


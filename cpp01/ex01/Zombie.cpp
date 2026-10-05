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

Zombie *zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return (NULL);
    Zombie *horde = new Zombie[N];
    // for (int i = 0; i < N; i++)
    // {
    //     std::cout << "Zombie "<< horde[i].getName() << " created." << std::endl;
    // }
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
        std::cout << "Zombie "<< i << " created." << std::endl;
        horde[i].announce();
    }
    return (horde);
}


#include "Zombie.hpp"
#include <sstream>

int main (void)
{
    Zombie* Zombies = zombieHorde(5, "Crazy");
    delete[] Zombies;
}

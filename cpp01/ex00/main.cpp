#include "Zombie.hpp"

int main (void)
{
	randomChump("apple");

    Zombie h("This is fun");
    h.announce();

    Zombie *z1 = newZombie("new zombie");
    delete z1;
}
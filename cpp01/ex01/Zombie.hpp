
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string name;

    public:
        Zombie();
        Zombie(std::string Name);
        ~Zombie(void);
        void announce(void);
        void setName(std::string Name);
        std::string getName();
};

Zombie *zombieHorde(int N, std::string name);

#endif
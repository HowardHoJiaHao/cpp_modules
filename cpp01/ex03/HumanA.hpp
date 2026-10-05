#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
    private:
        std::string name;
        Weapon &weapon; // this is the reference and not create a new one
    public:
        HumanA(std::string Name, Weapon &Weapon);
        void attack(void);

};

#endif
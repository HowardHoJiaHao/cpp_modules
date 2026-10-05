#include "FragTrap.hpp"

FragTrap::FragTrap ():ClapTrap()
{
    this->_hit_point = 100;
    this->_energy_point = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap " << this->_name << " is created." << std::endl;
}

FragTrap::FragTrap (std::string name):ClapTrap(name)
{
    this->_hit_point = 100;
    this->_energy_point = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap " << name << " named is created." << std::endl;
}

FragTrap::FragTrap (const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap " <<this->_name <<" copied is created." << std::endl;
}

FragTrap& FragTrap::operator= (const FragTrap &other)
{
    if (this == &other)
        return (*this);
    this->_name = other._name;
    this->_hit_point = other._hit_point;
    this->_energy_point = other._energy_point;
    this->_attack_damage = other._attack_damage;
    std::cout << "FragTrap " << this->_name <<" copied operator is created." << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name <<" was destroyed." << std::endl;
}


void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name  << " just high-5" << std::endl;
}

#include "ScavTrap.hpp"

ScavTrap::ScavTrap ():ClapTrap()
{
    this->_hit_point = 100;
    this->_energy_point = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap " << this->_name << " is created." << std::endl;
}

ScavTrap::ScavTrap (std::string name):ClapTrap(name)
{
    this->_hit_point = 100;
    this->_energy_point = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap " << name << " named is created." << std::endl;
}

ScavTrap::ScavTrap (const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap " <<this->_name <<" copied is created." << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap &other)
{
    if (this == &other)
        return (*this);
    this->_name = other._name;
    this->_hit_point = other._hit_point;
    this->_energy_point = other._energy_point;
    this->_attack_damage = other._attack_damage;
    std::cout << "ScavTrap " << this->_name <<" copied operator is created." << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name <<" was destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (_hit_point == 0)
    {
        std::cout << "ScavTrap "<< this->_name << " is dead and cant attack." <<  std::endl;
        return ;
    }
    if (_energy_point == 0)
    {
        std::cout << "ScavTrap "<< this->_name << " is out of energy point and cant attack." <<  std::endl;
        return ;
    }
    this->_energy_point --;

    std::cout << "ScavTrap " << this->_name << " attacks "
    << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap "<< this->_name << " is in gate keeper mode." << std::endl;
}
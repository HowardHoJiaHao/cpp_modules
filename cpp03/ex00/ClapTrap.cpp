#include "ClapTrap.hpp"

ClapTrap::ClapTrap ():_name("Default"), _hit_point(10), _energy_point(10), _attack_damage(0)
{
    std::cout << this->_name << " is created." << std::endl;
}

ClapTrap::ClapTrap (std::string name):_name(name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
    std::cout << name << " named is created." << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap &other)
{
    *this = other;
    std::cout << this->_name <<" copied is created." << std::endl;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &other)
{
    if (this == &other)
        return (*this);
    this->_name = other._name;
    this->_hit_point = other._hit_point;
    this->_energy_point = other._energy_point;
    this->_attack_damage = other._attack_damage;
    std::cout <<  this->_name <<" copied operator is created." << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << this->_name <<" was destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (_hit_point == 0)
    {
        std::cout << this->_name << " is dead and cant attack." <<  std::endl;
        return ;
    }
    if (_energy_point == 0)
    {
        std::cout << this->_name << " is out of energy point and cant attack." <<  std::endl;
        return ;
    }
    this->_energy_point --;

    std::cout << "ClapTrap " << this->_name << " attacks "
    << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hit_point = this->_hit_point - amount;
    
    if (this->_hit_point <= 0)
        this->_hit_point = 0;
    std::cout << this->_name <<" was attacked causing " << amount << " damage. Left with "
    << this->_hit_point << " hit point."<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hit_point == 0)
    {
        std::cout << this->_name << " is dead and cant be repaired" <<  std::endl;
        return ;
    }

    if (_energy_point == 0)
    {
        std::cout << this->_name << " is out of energy point and cant be repaired" <<  std::endl;
        return ;
    }
    this->_hit_point += amount;
    this->_energy_point --; 
    std::cout << "ClapTrap " << this->_name << " heal itself "
    << amount << " hit point, current hitpoint is " << this->_hit_point << std::endl;
}

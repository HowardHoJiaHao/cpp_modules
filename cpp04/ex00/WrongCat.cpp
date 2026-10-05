#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal("WrongCat")
{
    std::cout << "WrongCat " << _type << " Constructor Created" << std::endl;
}

WrongCat::WrongCat(const std::string &type):WrongAnimal(type)
{
    std::cout << "WrongCat " << type <<" Constructor Created" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
    if (this == &copy)
        return (*this);
    this->_type = copy._type;
    std::cout << "WrongCat " << _type << " copy operator Constructor Created" << std::endl;
    return (*this);
}

WrongCat::WrongCat(const WrongCat& copy):WrongAnimal(copy._type)
{
    std::cout << "WrongCat " << _type << " copy Constructor Created" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat " << _type << " destructor Created" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat default make sound is MEOW. " << std::endl;
}
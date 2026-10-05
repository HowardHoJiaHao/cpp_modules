#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_type("Default")
{
    std::cout << "WrongAnimal " << _type << " Constructor Created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type):_type(type)
{
    std::cout << "WrongAnimal " << type <<" Constructor Created" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
    if (this == &copy)
        return (*this);
    this->_type = copy._type;
    std::cout << "WrongAnimal " << _type << "copy operator Constructor Created" << std::endl;
    return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy):_type(copy._type)
{
    std::cout << "WrongAnimal " << _type << " copy Constructor Created" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal " << _type << " destructor Created" << std::endl;
}

const std::string& WrongAnimal::getType(void) const
{
	// std::cout << "the type of this WrongAnimal is " << _type << std::endl;
    return _type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal default make sound is MUAHAHAHH. " << std::endl;
}
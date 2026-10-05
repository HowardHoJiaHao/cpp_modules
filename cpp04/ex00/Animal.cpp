#include "Animal.hpp"

Animal::Animal():_type("Default")
{
    std::cout << "Animal " << _type << " Constructor Created" << std::endl;
}

Animal::Animal(std::string type):_type(type)
{
    std::cout << "Animal " << type <<" Constructor Created" << std::endl;
}

Animal& Animal::operator=(const Animal& copy)
{
    if (this == &copy)
        return (*this);
    this->_type = copy._type;
    std::cout << "Animal " << _type << "copy operator Constructor Created" << std::endl;
    return (*this);
}

Animal::Animal(const Animal& copy):_type(copy._type)
{
    std::cout << "Animal " << _type << " copy Constructor Created" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal " << _type << " destructor Created" << std::endl;
}

const std::string& Animal::getType(void) const
{
	// std::cout << "the type of this animal is " << _type << std::endl;
    return _type;
}

void Animal::makeSound() const
{
    std::cout << "Animal default make sound is MUAHAHAHH. " << std::endl;
}
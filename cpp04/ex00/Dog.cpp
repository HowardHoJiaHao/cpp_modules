#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
    std::cout << "Dog " << _type << " Constructor Created" << std::endl;
}

Dog::Dog(const std::string &type):Animal(type)
{
    std::cout << "Dog " << type <<" Constructor Created" << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
    if (this == &copy)
        return (*this);
    this->_type = copy._type;
    std::cout << "Dog " << _type << "copy operator Constructor Created" << std::endl;
    return (*this);
}

Dog::Dog(const Dog& copy):Animal(copy._type)
{
    std::cout << "Dog " << _type << " copy Constructor Created" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog " << _type << " destructor Created" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog default make sound is Bark. " << std::endl;
}
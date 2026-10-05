#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
    this->_brain = new Brain();
    std::cout << "Dog " << _type << " Constructor Created" << std::endl;
}

Dog::Dog(const std::string &type):Animal(type)
{
    this->_brain = new Brain();
    std::cout << "Dog " << type <<" Constructor Created" << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
    if (this == &copy)
        return (*this);
    this->_type = copy._type;
    delete this->_brain;
    this->_brain = new Brain(*copy._brain);
    std::cout << "Dog " << _type << "copy operator Constructor Created" << std::endl;
    return (*this);
}

Dog::Dog(const Dog& copy):Animal(copy._type)
{
    this->_brain = new Brain(*copy._brain);
    std::cout << "Dog " << _type << " copy Constructor Created" << std::endl;
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << "Dog " << _type << " destructor Created" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog default make sound is Bark. " << std::endl;
}

Brain* Dog::getBrain() const
{
    return this->_brain;
}

#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
    std::cout << "Cat " << _type << " Constructor Created" << std::endl;
}

Cat& Cat::operator=(const Cat& copy)
{
    if (this == &copy)
        return (*this);
    this->_type = copy._type;
    std::cout << "Cat " << _type << "copy operator Constructor Created" << std::endl;
    return (*this);
}

Cat::Cat(const Cat& copy):Animal(copy._type)
{
    std::cout << "Cat " << _type << " copy Constructor Created" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat " << _type << " destructor Created" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat default make sound is MEOW. " << std::endl;
}
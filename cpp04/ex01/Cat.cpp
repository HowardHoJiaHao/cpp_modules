
#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
    this->_brain = new Brain();
    std::cout << "Cat " << _type << " Constructor Created" << std::endl;
}

Cat& Cat::operator=(const Cat& copy)
{
    if (this == &copy)
        return (*this);

	// Animal::operator= (copy);
    this->_type = copy._type;
    delete this->_brain;
    this->_brain = new Brain(*copy._brain);
    std::cout << "Cat " << _type << "copy operator Constructor Created" << std::endl;
    return (*this);
}

Cat::Cat(const Cat& copy):Animal(copy._type)
{
    this->_brain = new Brain(*copy._brain);
    std::cout << "Cat " << _type << " copy Constructor Created" << std::endl;
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << "Cat " << _type << " destructor Created" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat default make sound is MEOW. " << std::endl;
}

Brain* Cat::getBrain() const
{
    return this->_brain;
}
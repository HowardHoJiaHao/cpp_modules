#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const std::string &type);
        Dog& operator=(const Dog& copy);
        Dog(const Dog& copy);
        ~Dog();

        void makeSound() const;
};

#endif
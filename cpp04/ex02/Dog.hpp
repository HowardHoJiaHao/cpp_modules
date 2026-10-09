#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* _brain;
    public:
        Dog();
        Dog& operator=(const Dog& copy);
        Dog(const Dog& copy);
        ~Dog();

        void makeSound() const;
        Brain* getBrain() const;
};

#endif
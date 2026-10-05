#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& copy);
        Animal& operator=(const Animal& copy);
        virtual ~Animal();

        virtual void makeSound() const = 0;
        const std::string& getType(void) const;

};

#endif

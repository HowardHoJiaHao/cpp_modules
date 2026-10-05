#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& copy);
        WrongAnimal& operator=(const WrongAnimal& copy);
        ~WrongAnimal();

        void makeSound() const;
        const std::string& getType(void) const;

};

#endif

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat& operator=(const WrongCat& copy);
        WrongCat(const WrongCat& copy);
        ~WrongCat();

        void makeSound() const;
};

#endif
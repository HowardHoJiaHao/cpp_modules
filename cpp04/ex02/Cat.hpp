#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* _brain;
    public:
        Cat();
        Cat(const std::string &type);
        Cat& operator=(const Cat& copy);
        Cat(const Cat& copy);
        ~Cat();

        void makeSound() const;
        Brain* getBrain() const;
};

#endif
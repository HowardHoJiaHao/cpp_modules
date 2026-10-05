#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string idea[100];
    public:
        Brain();
        Brain(const Brain& copy);
        Brain& operator=(const Brain& copy);
        ~Brain();

        const std::string& getIdea(int i)const; 
        void setIdea(int i, const std::string& idea);
};

#endif
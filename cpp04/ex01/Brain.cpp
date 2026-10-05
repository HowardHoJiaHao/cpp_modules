#include "Brain.hpp"

Brain::Brain ()
{
    std::cout << "Brain is created" << std::endl;
}

Brain::Brain (const Brain &copy)
{
    std::cout << "Brain is copied" << std::endl;
    *this = copy;
}


Brain& Brain::operator= (const Brain &copy)
{
    if (this == &copy)
        return *this;

    for (int i = 0; i < 100; i ++)
    {
        this->idea[i] = copy.idea[i];  
    }
    // std::cout << "Brain is copy operator" << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain is is destroyed" << std::endl;
}

const std::string& Brain::getIdea(int i) const 
{
    return this->idea[i];
}

void Brain::setIdea(int i, const std::string& idea)
{
    this->idea[i] = idea;
}
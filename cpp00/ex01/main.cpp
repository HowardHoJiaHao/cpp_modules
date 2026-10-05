
#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main (void)
{
    PhoneBook AlvinPhonebook;
    std::string line;
    
    while (true)
    {
        std::cout << "Enter Command (ADD, SEARCH, EXIT)" << std::endl;
        if (!std::getline(std::cin, line))
        {
            std::cout << "EOF detected, Exiting" << std::endl;
            break; 
        }
        if (line == "ADD")
            AlvinPhonebook.addContact();
        else if (line == "SEARCH")
            AlvinPhonebook.showContact();
        else if (line == "EXIT")
            break;
        else 
            std::cout << "Unknown Command" << std::endl;

    }
    return (0);
}
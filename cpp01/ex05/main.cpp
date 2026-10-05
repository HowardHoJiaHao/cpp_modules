#include "Harl.hpp"
#include <string>
#include <iostream>

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Incorrect Command. Enter one of this. ( DEBUG, INFO, WARNING, ERROR )" << std::endl;
        return 1; 
    }
    Harl singleHarl;
    std::string line = argv[1];
    singleHarl.complain(line);
}
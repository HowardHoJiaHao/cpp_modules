
#include <iostream>

// Safety	
// reference - High (cannot be null/re-assigned).	
// pointer - Lower (can point to garbage).

int main (void)
{
    std::string line = "HI THIS IS BRAIN";
    // Pointer
    std::string *stringPTR = &line;
    // Reference
    std::string &stringREF = line; 

    // stringREF = " edited";

    std::cout << "The Memory Address of line is : "<< &line << std::endl; 
    std::cout << "The Memory Address of line PTR is : "<< stringPTR << std::endl; 
    std::cout << "The Memory Address of line REF is : "<< &stringREF << std::endl;

    std::cout << "The value of line is : "<< line << std::endl; 
    std::cout << "The value of line PTR is : "<< *stringPTR << std::endl; 
    std::cout << "The value of line REF is : "<< stringREF << std::endl;

}

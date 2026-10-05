#include "Contact.hpp"

void Contact::createContact(std::string firstName, std::string lastName,
            std::string nickName, std::string secret, std::string phoneNumber)
{
    this->FirstName = firstName;
    this->LastName = lastName;
    this->NickName = nickName;
    this->Secret = secret;
    this->PhoneNumber = phoneNumber;
}

// line.substr(0,10)
std::string truncate(std::string line)
{
    if (line.length() > 10)
    {
        line.resize(9);
        line += '.';
    }
    return (line);
}

// Set Width 
// if the data is shorter than 10, fill the rest with empty spaces.
void Contact::showContact()
{
    std::cout << '|' << std::setw(10) << truncate(FirstName);
    std::cout << '|' << std::setw(10) << truncate(LastName);
    std::cout << '|' << std::setw(10) << truncate(NickName);
}

void Contact::showSingleContact()
{
    std::cout << "The First Name is : "<< FirstName << std::endl ;
    std::cout << "The Last Name is : " << LastName << std::endl ;
    std::cout << "The Nick Name is : " << NickName << std::endl ;
    std::cout << "The Secret is : "   << Secret << std::endl ;
    std::cout << "The Phone Number is : " << PhoneNumber << std::endl ;
}

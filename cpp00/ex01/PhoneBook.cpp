
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0), nextIndex(0)
{}

// if dont initialize the count will be garbage value
// int PhoneBook::getCount()
// {
//     return (this->count);
// }

void PhoneBook::addContact()
{
    
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string Secret;
    std::string PhoneNumber;

    std::cout << "Enter First Name" << std::endl;
    if (!std:: getline (std::cin, FirstName))
    {
        std::cout << "\n EOF detected, return to main menu\n";
        return ;
    }

    std::cout << "Enter Last Name " << std::endl;
    if (!std:: getline (std::cin, LastName))
    {
        std::cout << "\n EOF detected, return to main menu\n";
        return ;
    }

    std::cout << "Enter Nick Name " << std::endl;
    if (!std:: getline (std::cin, NickName))
    {
        std::cout << "\n EOF detected, return to main menu\n";
        return ;
    }

    std::cout << "Enter Secret " << std::endl;
    if (!std:: getline (std::cin, Secret))
    {
        std::cout << "\n EOF detected, return to main menu\n";
        return ;
    }

    std::cout << "Enter Phone Number " << std::endl;
    if (!std:: getline (std::cin, PhoneNumber))
    {
        std::cout << "\n EOF detected, return to main menu\n";
        return ;
    }

    if (FirstName.empty() || LastName.empty() || NickName.empty()
        || Secret.empty() || PhoneNumber.empty())
    {
        std::cout << "Unable to save.Contact cannot have empty field\n" << std::endl;
        return;
    }

    contact[nextIndex].createContact(FirstName, LastName, NickName, Secret, PhoneNumber);
    nextIndex = (nextIndex + 1) % 8;
    if (count < 8)
        count ++;
    std::cout << "Contact saved!\n";
     
}

void PhoneBook::showContact()
{
    if (count == 0)
    {
        std::cout << "PhoneBook is empty \n" << std::endl;
        return ;
    }
    std::cout << " Contact List \n";
    std::cout << "     index|First Name| Last Name|  NickName" << std::endl;
    for (int i = 0; i < count; i ++)
    {
        std::cout << "       [" << i + 1 << "]";
        contact[i].showContact();
        std::cout << std::endl;
    }
    std::cout << " Enter Index for detail " << std::endl;
    std::string line;
    if (!std::getline(std::cin, line))
    {
        std::cout << " EOF detected, returning to main." << std::endl;
        return ;
    }
    std::istringstream iss(line);
    int index;
    if ( !(iss >> index) || index - 1 >= count || index <= 0)
    {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    contact[index - 1].showSingleContact();
    std::cout << std::endl;
}

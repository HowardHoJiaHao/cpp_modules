#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string Secret;
        std::string PhoneNumber;

    public:
        void createContact(std::string firstName, std::string lastName,
            std::string nickName, std::string secret, std::string phoneNumber);
        void showContact();
        void showSingleContact();
};

#endif
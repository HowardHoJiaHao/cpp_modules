#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <sstream>
#include <string>
#include <iostream>

class PhoneBook
{
    private:
        Contact contact[8];
        int count;
        int nextIndex;
    public:
        PhoneBook();
        void addContact();
        void showContact();
};

#endif
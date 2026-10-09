# CPP00

> 42 Common Core · Rank 04 · Subject: [en.subject.pdf](en.subject.pdf)

## Introduction
The first C++ module. It covers **namespaces, classes, member functions, stdio streams, initialization lists, `static` and `const`**. It is the step from C to C++: the exercises must be solved "in a C++ manner", with `std::string` and `std::cout` instead of `char *` and `printf`.

All the code is written in **C++98** and compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

## Exercises
| Folder | Subject title | Executable | Status |
|---|---|---|---|
| [ex00](ex00) | Megaphone | `megaphone` | Done |
| [ex01](ex01) | My Awesome PhoneBook | `phonebook` | Done |
| – | ex02: The Job Of Your Dreams | – | Optional, not done |

### ex00 – Megaphone
Prints all the arguments in uppercase, one after the other. With no arguments, it prints a feedback noise.
```bash
cd ex00 && make
./megaphone "shhhhh... I think the students are asleep..."
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
./megaphone
```

Result:
```
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

### ex01 – My Awesome PhoneBook
A small phonebook built from two classes:
- **`Contact`** – one entry: first name, last name, nickname, phone number and darkest secret.
- **`PhoneBook`** – a fixed array of 8 `Contact` objects (dynamic allocation is forbidden). When a 9th contact is added, it replaces the oldest one.

The program waits for one of three commands:

| Command | Effect |
|---|---|
| `ADD` | Asks for each field one at a time. A contact with an empty field is not saved. |
| `SEARCH` | Shows the contacts as a table of 4 columns: index, first name, last name and nickname. Each column is 10 characters wide and right-aligned. Text longer than 10 characters is cut and its last character is replaced by `.`. Then it asks for an index and prints that contact's fields, one per line. A wrong index prints `Invalid index`. |
| `EXIT` | Quits the program. The contacts are lost forever. |

Any other input prints `Unknown Command`. `Ctrl-D` (EOF) is handled at every prompt.

Example session:
```bash
cd ex01 && make && ./phonebook
```
```
Enter Command (ADD, SEARCH, EXIT)
SEARCH
 Contact List 
     index|First Name| Last Name|  NickName
       [1]|      John|     Smith|    Johnny
       [2]|Christoph.|Wellington|     Chris
 Enter Index for detail 
2
The First Name is : Christopher
The Last Name is : Wellington
The Nick Name is : Chris
The Secret is : Loves pineapple pizza
The Phone Number is : 0198765432
```

### ex02 – The Job Of Your Dreams (optional)
Recreate a lost `Account.cpp` from `Account.hpp`, `tests.cpp` and a log file. The subject says the module can be passed without it, and it is not included here.

## Compile and Run
Each exercise has its own `Makefile`. `cd` into the folder and run `make`. The `clean`, `fclean` and `re` targets are also available.

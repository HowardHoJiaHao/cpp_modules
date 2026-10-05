# C++ Modules (CPP00 – CPP09)

> 42 Common Core · Rank 04 – 05

## Introduction
The C++ modules are a series of ten short modules that introduce **C++** and **object-oriented programming**, starting from classes and going up to templates and the STL. Modules 00–04 are part of Rank 04 and modules 05–09 are part of Rank 05.

All the code is written in **C++98** and compiled with `c++ -Wall -Wextra -Werror -std=c++98`. Each exercise has its own folder and `Makefile`.

## Modules
| Module | Topics | Exercises |
|:---:|---|---|
| [CPP00](cpp00) | Namespaces, classes, member functions, `iostream`, static and const members | `ex00` megaphone · `ex01` PhoneBook with `Contact` objects |
| [CPP01](cpp01) | Memory allocation, pointers vs references, file streams, `switch` | `ex00` Zombie on the heap vs the stack · `ex01` zombie horde · `ex02` pointers vs references · `ex03` `Weapon`, `HumanA`, `HumanB` · `ex04` replace a string in a file · `ex05` Harl's complaint levels |
| [CPP02](cpp02) | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form | `ex00` – `ex02` a fixed-point number class with comparison and arithmetic operators |
| [CPP03](cpp03) | Inheritance | `ex00` `ClapTrap` · `ex01` `ScavTrap` · `ex02` `FragTrap` |
| [CPP04](cpp04) | Subtype polymorphism, abstract classes, deep copies | `ex00` `Animal`, `Dog`, `Cat` and `WrongAnimal` · `ex01` a `Brain` deep-copied with each animal · `ex02` abstract `Animal` |
| [CPP05](cpp05) | Exceptions, `try` / `catch` | `ex00` `Bureaucrat` · `ex01` `Form` · `ex02` `AForm` with Shrubbery, Robotomy and Presidential Pardon forms · `ex03` `Intern` |
| [CPP06](cpp06) | C++ casts | `ex00` `ScalarConverter` (char, int, float, double) · `ex01` `Serializer` with `reinterpret_cast` · `ex02` identifying `A`, `B` or `C` with `dynamic_cast` |
| [CPP07](cpp07) | Function and class templates | `ex00` `swap`, `min`, `max` · `ex01` `iter` · `ex02` `Array` class template |
| [CPP08](cpp08) | Templated containers, iterators, algorithms | `ex00` `easyfind` · `ex01` `Span` · `ex02` `MutantStack` (an iterable `std::stack`) |
| [CPP09](cpp09) | The STL | `ex00` Bitcoin exchange rates from a CSV database with `std::map` · `ex01` Reverse Polish Notation calculator with `std::stack` · `ex02` Ford–Johnson merge-insert sort with `std::vector` and `std::deque` |

## Clone
Clone the repository:
```bash
git clone https://github.com/HowardHoJiaHao/cpp_modules.git
```

## Compile and Run
To compile an exercise, `cd` into its folder and run `make`. For example:
```bash
cd cpp_modules/cpp09/ex01
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

Result:
```
42
```

More examples from CPP09:
```bash
cd ../ex00 && make && ./btc input.csv      # bitcoin value on each date in input.csv
cd ../ex02 && make && ./PmergeMe 3 5 9 7 4 # sorts the numbers with both containers
```

Result of `PmergeMe`:
```
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::vector : 20 us
Time to process a range of 5 elements with std::deque : 51 us
```

Each `Makefile` also has `clean`, `fclean` and `re` targets.

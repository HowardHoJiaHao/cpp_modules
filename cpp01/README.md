# CPP01

> 42 Common Core · Rank 04 · Subject: [en.subject.pdf](en.subject.pdf)

## Introduction
This module covers **memory allocation, pointers to members, references and the `switch` statement**. The exercises compare the **stack and the heap**, **pointers and references**, and introduce **file streams** and **pointers to member functions**.

All the code is written in **C++98** and compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

## Exercises
| Folder | Subject title | Executable | Status |
|---|---|---|---|
| [ex00](ex00) | BraiiiiiiinnnzzzZ | `ex00` | Done |
| [ex01](ex01) | Moar brainz! | `ex01` | Done |
| [ex02](ex02) | HI THIS IS BRAIN | `ex02` | Done |
| [ex03](ex03) | Unnecessary violence | `ex03` | Done |
| [ex04](ex04) | Sed is for losers | `ex04` | Done |
| [ex05](ex05) | Harl 2.0 | `ex05` | Done |
| – | ex06: Harl filter | – | Optional, not done |

### ex00 – BraiiiiiiinnnzzzZ
A `Zombie` class with a private `name` and an `announce()` member function that prints `<name>: BraiiiiiiinnnzzzZ...`. The destructor prints a message, so you can see when each zombie is destroyed.
- `newZombie(name)` creates a zombie **on the heap** with `new` and returns it, so it can be used outside the function. The caller has to `delete` it.
- `randomChump(name)` creates a zombie **on the stack** and makes it announce itself. It is destroyed as soon as the function returns.

Use the stack when the object is only needed in the current scope, and the heap when it has to outlive it.

```
apple: BraiiiiiiinnnzzzZ...
apple zombie destroyed
This is fun: BraiiiiiiinnnzzzZ...
new zombie zombie destroyed
This is fun zombie destroyed
```
`apple` comes from `randomChump` and dies straight away. `new zombie` comes from `newZombie` and is deleted by hand. `This is fun` is a local variable in `main`, destroyed when `main` returns.

### ex01 – Moar brainz!
`zombieHorde(N, name)` allocates `N` zombies in a **single** allocation (`new Zombie[N]`), gives each one the same name and returns a pointer to the first. The horde is freed with `delete[]`.
```
Zombie 0 created.
Crazy: BraiiiiiiinnnzzzZ...
...
Zombie 4 created.
Crazy: BraiiiiiiinnnzzzZ...
Crazy zombie destroyed
...
```

### ex02 – HI THIS IS BRAIN
A string `"HI THIS IS BRAIN"`, a pointer to it (`stringPTR`) and a reference to it (`stringREF`). The program prints the three addresses, which are all the same, then the three values. A reference is just another name for the same variable.
```
The Memory Address of line is : 0x7ffd53e2b500
The Memory Address of line PTR is : 0x7ffd53e2b500
The Memory Address of line REF is : 0x7ffd53e2b500
The value of line is : HI THIS IS BRAIN
The value of line PTR is : HI THIS IS BRAIN
The value of line REF is : HI THIS IS BRAIN
```

### ex03 – Unnecessary violence
A `Weapon` with a `type`, a `getType()` that returns a const reference and a `setType()`. Two humans use it:
- **`HumanA`** gets its weapon in the constructor and is always armed, so it stores a **reference** to the `Weapon`.
- **`HumanB`** may have no weapon and gets one later with `setWeapon()`, so it stores a **pointer** (which can be `NULL`).

Both refer to the original `Weapon`, so calling `setType()` on the club changes what the human attacks with:
```
Bob attacks with their crude spiked club
Bob attacks with their some other type of club
...
Jim attacks with their crude spiked club
Jim attacks with their some most powerful type of club
```

### ex04 – Sed is for losers
```bash
./ex04 <filename> <s1> <s2>
```
Copies `<filename>` into `<filename>.replace`, replacing every `s1` with `s2`. `std::string::replace` and C file functions are forbidden, so each line is rebuilt with `find` and `substr`, and the files are read and written with `std::ifstream` and `std::ofstream`. A wrong number of arguments, an empty filename or `s1`, or a file that can't be opened are all reported as errors.

```bash
printf 'hello world\nhello there\n' > test.txt
./ex04 test.txt hello bye
cat test.txt.replace
```

Result:
```
bye world
bye there
```
The folder also has a sample `filename.txt` to try it on.

### ex05 – Harl 2.0
`Harl` has four private member functions, `debug()`, `info()`, `warning()` and `error()`, and one public `complain(level)`. `complain` looks the level up in an array of strings and calls the matching function through an **array of pointers to member functions**, with no `if` / `else if` chain.
```bash
./ex05 WARNING
```

Result:
```
I think I deserve to have some extra bacon for free. I’ve been coming foryears whereas you started working here since last month.
```
Any other level prints `Incorrect Command. Enter one of this. ( DEBUG, INFO, WARNING, ERROR )`.

### ex06 – Harl filter (optional)
Print all messages from the given level and above, using a `switch`. The subject says the module can be passed without it, and it is not included here.

## Compile and Run
Each exercise has its own `Makefile`. `cd` into the folder and run `make`. The `clean`, `fclean` and `re` targets are also available.

# CPP03

> 42 Common Core · Rank 04 · Subject: [en.subject.pdf](en.subject.pdf)

## Introduction
This module is about **inheritance**. It starts with a small robot class, `ClapTrap`, and then derives new robots from it that reuse its attributes and behaviour but change their stats, their messages and add their own abilities.

All the code is written in **C++98** and compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

## Exercises
| Folder | Subject title | Executable | Status |
|---|---|---|---|
| [ex00](ex00) | Aaaaand... OPEN! | `ex00` | Done |
| [ex01](ex01) | Serena, my love! | `ex01` | Done |
| [ex02](ex02) | Repetitive work | `ex01` | Done |
| – | ex03: Now it's weird! | – | Optional, not done |

## The robots
| Class | Inherits from | Hit points | Energy points | Attack damage | Special ability |
|---|---|:---:|:---:|:---:|---|
| `ClapTrap` | – | 10 | 10 | 0 | – |
| `ScavTrap` | `ClapTrap` | 100 | 50 | 20 | `guardGate()` – enters Gate keeper mode |
| `FragTrap` | `ClapTrap` | 100 | 100 | 30 | `highFivesGuys()` – asks for a high five |

Every robot has `attack(target)`, `takeDamage(amount)` and `beRepaired(amount)`:
- Attacking and repairing each cost **1 energy point**.
- A robot with no hit points or no energy points can't do anything.
- Every action, constructor and destructor prints a message.

### ex00 – Aaaaand... OPEN!
The `ClapTrap` base class.
```
ClapTrap Jack attacks flying, causing 0 points of damage!
Jack was attacked causing 3 damage. Left with 7 hit point.
ClapTrap Jack heal itself 2 hit point, current hitpoint is 9
...
Jack was attacked causing 999 damage. Left with 0 hit point.
Jack is dead and cant attack.
Jack is dead and cant be repaired
```

### ex01 – Serena, my love!
`ScavTrap` inherits from `ClapTrap`. The `ClapTrap` attributes are `protected`, so `ScavTrap` can set them to its own values. Its constructors, destructor and `attack()` print their own messages.

The tests show the **construction and destruction chain**: the `ClapTrap` part is built first and destroyed last, because a derived object is built on top of its base.
```
ClapTrap Rex named is created.
ScavTrap Rex named is created.
ScavTrap Rex attacks Intruder, causing 20 points of damage!
...
ScavTrap Rex is in gate keeper mode.
...
ScavTrap Rex was destroyed.
ClapTrap Rex was destroyed.
```

### ex02 – Repetitive work
`FragTrap` also inherits from `ClapTrap`, with different stats, messages and `highFivesGuys()`.
```
ClapTrap Rex named is created.
FragTrap Rex named is created.
ClapTrap Rex attacks Intruder, causing 30 points of damage!
...
FragTrap Rex just high-5
...
FragTrap Rex was destroyed.
ClapTrap Rex was destroyed.
```

### ex03 – Now it's weird! (optional)
A `DiamondTrap` that inherits from both `ScavTrap` and `FragTrap` (diamond inheritance with `virtual` base classes). The subject says the module can be passed without it, and it is not included here.

## Compile and Run
Each exercise has its own `Makefile`. `cd` into the folder and run `make`. The `clean`, `fclean` and `re` targets are also available.
```bash
cd ex02 && make && ./ex01
```

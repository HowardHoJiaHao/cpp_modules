# CPP04

> 42 Common Core · Rank 04 · Subject: [en.subject.pdf](en.subject.pdf)

## Introduction
This module covers **subtype polymorphism, abstract classes and interfaces**. With `virtual` functions, a call made through a base-class pointer runs the derived class's version. The exercises also show why a base class needs a **virtual destructor**, and how to make **deep copies** of objects that own memory.

All the code is written in **C++98** and compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

## Exercises
| Folder | Subject title | Executable | Status |
|---|---|---|---|
| [ex00](ex00) | Polymorphism | `ex00` | Done |
| [ex01](ex01) | I don't want to set the world on fire | `ex01` | Done |
| [ex02](ex02) | Abstract class | `ex02` | Done |
| – | ex03: Interface & recap | – | Optional, not done |

### ex00 – Polymorphism
`Animal` has a protected `type` and a `virtual makeSound()`. `Dog` and `Cat` inherit from it, set `type` to `"Dog"` and `"Cat"`, and override `makeSound()`. Through an `Animal*`, each animal makes its own sound.

To show what goes wrong without `virtual`, `WrongCat` inherits from `WrongAnimal`, whose `makeSound()` is **not** virtual. Through a `WrongAnimal*`, a `WrongCat` makes the `WrongAnimal` sound.
```
Animal default make sound is MUAHAHAHH. 
Cat default make sound is MEOW. 
Dog default make sound is Bark. 
...
WrongAnimal default make sound is MUAHAHAHH. 
WrongAnimal default make sound is MUAHAHAHH. 
```

### ex01 – I don't want to set the world on fire
A `Brain` class holds an array of 100 `std::string` ideas. Each `Dog` and `Cat` creates its own `Brain` with `new` and deletes it in its destructor.
- `main` fills an array of 10 `Animal*`, half `Dog` and half `Cat`, and deletes them all through `Animal*`. Because `Animal`'s destructor is `virtual`, the `Dog` / `Cat` destructor runs first, then `Animal`'s, and no `Brain` leaks.
- Copying a `Dog` or a `Cat` makes a **deep copy**: the copy gets its own new `Brain`, so changing one doesn't change the other.

Deep copy test:
```
Animal Dog Constructor Created
Brain is created
Dog Dog Constructor Created
stick
kick
Animal Dog Constructor Created
Brain is copied
Dog Dog copy Constructor Created
funny
kick
stick
kick
```
After the copy, `b`'s first idea is changed to `funny`, and `a` still has `stick`.

### ex02 – Abstract class
A plain `Animal` makes no sense, so `makeSound()` is made **pure virtual** (`= 0`). This makes `Animal` an abstract class that can't be instantiated, while `Dog` and `Cat` work as before. The class keeps the name `Animal`; the subject allows, but doesn't require, renaming it `AAnimal`.
```
Cat default make sound is MEOW. 
Dog default make sound is Bark. 
```

### ex03 – Interface & recap (optional)
`AMateria`, `Ice`, `Cure`, `ICharacter`, `Character`, `IMateriaSource` and `MateriaSource`, built with pure abstract classes used as interfaces. The subject says the module can be passed without it, and it is not included here.

## Compile and Run
Each exercise has its own `Makefile`. `cd` into the folder and run `make`. The `clean`, `fclean` and `re` targets are also available.

# CPP05

> 42 Common Core · Rank 05 · Subject: [en.subject.pdf](en.subject.pdf)

## Introduction
This module covers **repetition and exceptions**. It builds an office of bureaucrats who sign and execute forms, where every invalid action throws an **exception** that is caught with `try` / `catch`.

Every class is in Orthodox Canonical Form, except the exception classes. All the code is written in **C++98** and compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

## Exercises
| Folder | Subject title | Executable | Status |
|---|---|---|---|
| [ex00](ex00) | Mommy, when I grow up, I want to be a bureaucrat! | `bureaucrat` | Done |
| [ex01](ex01) | Form up, maggots! | `bureaucrat` | Done |
| [ex02](ex02) | No, you need form 28B, not 28C... | `bureaucrat` | Done |
| [ex03](ex03) | At least this beats coffee-making | `bureaucrat` | Done |

### ex00 – Bureaucrat
A `Bureaucrat` has a constant name and a grade from **1 (highest) to 150 (lowest)**.
- Creating a bureaucrat with a grade outside 1–150 throws `Bureaucrat::GradeTooHighException` or `Bureaucrat::GradeTooLowException`. Both inherit from `std::exception` and override `what()`.
- `incrementGrade()` moves the grade **towards 1** (3 becomes 2) and `decrementGrade()` moves it towards 150. Going past either end throws the same exceptions.
- `operator<<` prints `<name>, bureaucrat grade <grade>.`
```
=== test1 : successful case === 
Alice, bureaucrat grade 1.
Bob, bureaucrat grade 150.
...
 === Test4 : increament or Decrement === 
initial: test, bureaucrat grade 3.
after increment: test, bureaucrat grade 2.
after increment: test, bureaucrat grade 1.
Exception: Grade is too high ! (must be >= 1)
```

### ex01 – Form
A `Form` has a constant name, a `signed` flag (false at first), a constant grade needed to sign it and a constant grade needed to execute it.
- `Form::beSigned(bureaucrat)` signs the form if the bureaucrat's grade is high enough, and throws `Form::GradeTooLowException` otherwise.
- `Bureaucrat::signForm(form)` tries to sign and prints `<bureaucrat> signed <form>` or `<bureaucrat> couldn't sign <form> because <reason>`.
```
bob signed tax form
after: Form: tax form, signed: yes, grade to sign: 50, grade to execute: 30
...
jim couldnt sign secret document because Form grade is too low! (must be <= 150)
```

### ex02 – AForm and the concrete forms
`Form` becomes the abstract class `AForm`. Its `execute(executor)` checks that the form is signed and that the executor's grade is high enough, then runs the concrete form's action. `Bureaucrat::executeForm(form)` tries to execute it and prints the result.

| Form | Sign grade | Exec grade | Action |
|---|:---:|:---:|---|
| `ShrubberyCreationForm` | 145 | 137 | Writes ASCII trees into a `<target>_shrubbery` file |
| `RobotomyRequestForm` | 72 | 45 | Makes drilling noises, then robotomizes the target 50% of the time |
| `PresidentialPardonForm` | 25 | 5 | Says the target has been pardoned by Zaphod Beeblebrox |

```
 === Test 1: execute unsigned form === 
boss couldnt execute ShrubberyCreationForm because Form is not signed
...
 ===== test5 : successful execution === 
boss execute ShrubberyCreationForm
criminal has been pardoned by Zaphod Beeblebrox
boss execute PresidentialPardonForm

 === test6 : robotomy randomness === 
* ROBOTTTT ARGGG *
marvin has been robotomized successfully
...
* ROBOTTTT ARGGG *
Robotomy failed on marvin
```
Running it creates `garden_shrubbery` and `poly_tree_shrubbery` in the current folder.

### ex03 – Intern
An `Intern` has no name and no grade. `makeForm(formName, target)` returns a new form of the requested kind and prints `Intern creates <form>`. The form names are looked up in an array next to an **array of pointers to creator functions**, so there is no `if` / `else if` chain.

| Form name | Creates |
|---|---|
| `"shrubbery creation"` | `ShrubberyCreationForm` |
| `"robotomy request"` | `RobotomyRequestForm` |
| `"presidential pardon"` | `PresidentialPardonForm` |

```
Intern creates robotomy request
...
 Intern cannot create "coffee request"
```

## Compile and Run
Each exercise has its own `Makefile`. `cd` into the folder and run `make`. The `clean`, `fclean` and `re` targets are also available.
```bash
cd ex02 && make && ./bureaucrat
```

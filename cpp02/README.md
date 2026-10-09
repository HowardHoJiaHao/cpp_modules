# CPP02

> 42 Common Core · Rank 04 · Subject: [en.subject.pdf](en.subject.pdf)

## Introduction
This module covers **ad-hoc polymorphism, operator overloading and the Orthodox Canonical class form**. Over the exercises, a `Fixed` class that represents a **fixed-point number** is built step by step.

A fixed-point number is stored as a plain integer with a fixed number of fractional bits. Here there are always **8** fractional bits, so the real value is `raw / 256` and the smallest step is `1 / 256 = 0.00390625`. Compared with floating point, fixed-point gives the same precision over the whole range and only needs integer maths.

A class in **Orthodox Canonical Form** has:
- a default constructor
- a copy constructor
- a copy assignment operator
- a destructor

All the code is written in **C++98** and compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

## Exercises
| Folder | Subject title | Executable | Status |
|---|---|---|---|
| [ex00](ex00) | My First Class in Orthodox Canonical Form | `ex00` | Done |
| [ex01](ex01) | Towards a more useful fixed-point number class | `ex01` | Done |
| [ex02](ex02) | Now we're talking | `ex02` | Done |
| – | ex03: BSP | – | Optional, not done |

### ex00 – My First Class in Orthodox Canonical Form
`Fixed` stores the raw integer value and a `static const int` of 8 fractional bits. It has the four canonical members plus `getRawBits()` and `setRawBits()`. Each one prints a message, so you can follow the calls:
```
Default constructor called
Copy constructor called
Copy assignation operator called
getRawBits member function called
Default constructor called
Copy assignation operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
```

### ex01 – Towards a more useful fixed-point number class
Adds conversions to and from `int` and `float`:

| Member | How it works |
|---|---|
| `Fixed(int const n)` | `raw = n << 8` |
| `Fixed(float const f)` | `raw = roundf(f * 256)` |
| `float toFloat() const` | `raw / 256.0` |
| `int toInt() const` | `raw >> 8` |
| `operator<<` | Prints `toFloat()` to the stream |

```
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
```
`42.42f` comes out as `42.4219`, because `42.42` can't be stored exactly with 8 fractional bits.

### ex02 – Now we're talking
Adds operator overloads:
- the 6 comparison operators: `>`, `<`, `>=`, `<=`, `==`, `!=`
- the 4 arithmetic operators: `+`, `-`, `*`, `/`
- pre- and post-increment and decrement, which move the value by the smallest step (`1 / 256`)
- static `min` and `max`, each with a `const` and a non-`const` version

Output of the subject's test, followed by extra tests:
```
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016

 --- comparison tests ---
x: 10 y: 42
x < y : 1
...
 --- Arithmetic tests --- 
p: 2.5 q: 1.25
p + q = 3.75
p - q = 1.25
p * q = 3.125
p / q = 2
...
```
Dividing by 0 is allowed to crash, as the subject says.

### ex03 – BSP (optional)
A `Point` class and a `bsp()` function that tells if a point is inside a triangle. The subject says the module can be passed without it, and it is not included here.

## Compile and Run
Each exercise has its own `Makefile`. `cd` into the folder and run `make`. The `clean`, `fclean` and `re` targets are also available.

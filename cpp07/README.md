# CPP07

> 42 Common Core · Rank 05 · Subject: [en.subject.pdf](en.subject.pdf)

## Introduction
This module is about **C++ templates**. A template is written once and the compiler generates a version of it for each type it is used with. Templates have to be visible wherever they are used, so they live in headers or in `.tpp` files included by a header.

All the code is written in **C++98** and compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

## Exercises
| Folder | Subject title | Executable | Status |
|---|---|---|---|
| [ex00](ex00) | Start with a few functions | `whatever` | Done |
| [ex01](ex01) | Iter | `iter` | Done |
| [ex02](ex02) | Array | `array` | Done |

### ex00 – Start with a few functions
Three function templates that work with any type that supports comparison:
- `swap(a, b)` swaps two values.
- `min(a, b)` returns the smaller one, or the second one if they are equal.
- `max(a, b)` returns the greater one, or the second one if they are equal.
```
a = 3, b = 2
min( a, b ) = 2
max( a, b ) = 3
c = chaine2, d = chaine1
min( c, d ) = chaine1
max( c, d ) = chaine2
```

### ex01 – Iter
`iter(array, length, function)` calls `function` on every element of the array. It works with any array type, including `const` arrays, and the function can itself be a function template.
```
original char array: a b c d e 
 test modified char array: A B C 
Original string array: hello world templates 
 test modified str array: HELLO WORLD TEMPLATES 
original number: 1 2 3 4 5 
incremented number: 2 3 4 5 6 
const numbers: 10 20 30 
```

### ex02 – Array
`Array<T>` is a class template for a fixed-size array:
- `Array()` creates an empty array, and `Array(n)` creates `n` default-initialized elements.
- Memory is allocated with `new[]`, and only when needed.
- The copy constructor and the assignment operator make **deep copies**, so changing one array never changes the other.
- `operator[]` throws an exception when the index is out of bounds.
- `size()` returns the number of elements.
```
 === test2: parameteraized array (int) ===
size: 5
Values initialized to: 0 0 0 0 0 
Vaues after modification: 0 2 4 6 8 

 === test3: out of bounds exception ===
Accessing valid index 2: 4
Accessing invalid index 10 ...
exception caught: Index out of bounds!

 === test4: copy constructor(deep copy) ===
...
Original[0]: 999
Copy[0]: 0 (should not be 999)
```

## Compile and Run
Each exercise has its own `Makefile`. `cd` into the folder and run `make`. The `clean`, `fclean` and `re` targets are also available.

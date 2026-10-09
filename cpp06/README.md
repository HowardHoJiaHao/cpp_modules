# CPP06

> 42 Common Core · Rank 05 · Subject: [en.subject.pdf](en.subject.pdf)

## Introduction
This module is about the **C++ casts**. Each exercise uses a different one:

| Cast | Used for | Exercise |
|---|---|---|
| `static_cast` | Normal conversions between related types, such as `double` to `int` | ex00 |
| `reinterpret_cast` | Reading the bits of a value as another type, such as a pointer as an integer | ex01 |
| `dynamic_cast` | Checking at run time which derived class an object really is | ex02 |

All the code is written in **C++98** and compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

## Exercises
| Folder | Subject title | Executable | Status |
|---|---|---|---|
| [ex00](ex00) | Conversion of scalar types | `convert` | Done |
| [ex01](ex01) | Serialization | `serializer` | Done |
| [ex02](ex02) | Identify real type | `identify` | Done |

### ex00 – Conversion of scalar types
`ScalarConverter` has a single static member function, `convert`. Its constructors are private, so the class can't be instantiated.

`convert` first detects which kind of literal the string is (`char`, `int`, `float` or `double`), converts it to that type, and then explicitly casts it to the other three. It also handles the pseudo-literals `-inff`, `+inff`, `nanf`, `-inf`, `+inf` and `nan`. Conversions that make no sense or overflow print `impossible`, and a `char` that can't be printed shows `Non displayable`.
```bash
./convert 0
./convert nan
./convert 42.0f
./convert a
./convert 2147483648
```

Result:
```
char: Non displayable
int: 0
float: 0.0f
double: 0.0

char: impossible
int: impossible
float: nanf
double: nan

char: '*'
int: 42
float: 42.0f
double: 42.0

char: 'a'
int: 97
float: 97.0f
double: 97.0

char: impossible (oveflow / underflow)
int: impossible (overflow / underflow)
float: 2147483648.0f
double: 2147483648.0
```

### ex01 – Serialization
`Serializer` has two static functions:
- `uintptr_t serialize(Data* ptr)` turns a pointer into an unsigned integer.
- `Data* deserialize(uintptr_t raw)` turns it back into a pointer.

Both use `reinterpret_cast`. `Data` is a struct with an `int`, a `std::string` and a `double`. The test serializes a `Data` address, deserializes it and checks that the result equals the original pointer.
```
 Address of original: 0x7ffeeb3a3800
 value of raw: 140732844881920
 another way in representing address - Deserioalized pointer: 0x7ffeeb3a3800

Verification: 
 are restored and original the same? yes
```

### ex02 – Identify real type
`Base` has only a public virtual destructor. `A`, `B` and `C` are empty classes that inherit from it.
- `generate()` randomly creates an `A`, `B` or `C` and returns it as a `Base*`.
- `identify(Base* p)` tries `dynamic_cast<A*>`, `<B*>` and `<C*>`. A failed pointer cast returns `NULL`.
- `identify(Base& p)` does the same with references, without using any pointer. A failed reference cast throws `std::bad_cast`, so each try is wrapped in `try` / `catch`.

The `<typeinfo>` header is forbidden.
```
 === testing generate() and  identify () === 
Test 1: B
Test 2: A
Test 3: A
Test 4: C
...
 ===testing with known types === 
A pointer: A
A reference: A
B pointer: B
B reference: B
C pointer: C
C reference: C
```

## Compile and Run
Each exercise has its own `Makefile`. `cd` into the folder and run `make`. The `clean`, `fclean` and `re` targets are also available.

# CPP08

> 42 Common Core · Rank 05 · Subject: [en.subject.pdf](en.subject.pdf)

## Introduction
This module covers **templated containers, iterators and algorithms**: the STL containers (`std::vector`, `std::list`, `std::stack`, ...) and the functions in `<algorithm>` that work on them through iterators.

All the code is written in **C++98** and compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

## Exercises
| Folder | Subject title | Executable | Status |
|---|---|---|---|
| [ex00](ex00) | Easy find | `easyfind` | Done |
| [ex01](ex01) | Span | `span` | Done |
| [ex02](ex02) | Mutated abomination | `mutantstack` | Done |

### ex00 – Easy find
`easyfind(container, value)` is a function template that finds the first occurrence of an integer in any container of integers. It uses `std::find` and throws a `std::runtime_error` when the value isn't there.
```
Found it vector: 20
Found in list: 15
exception: value not found
```

### ex01 – Span
`Span` holds at most `N` integers in a `std::vector<int>`. `N` is given to the constructor.
- `addNumber(n)` adds one number, and throws if the span is already full.
- `addNumbers(begin, end)` adds a whole range of iterators in one call.
- `shortestSpan()` sorts a copy of the numbers and returns the smallest gap between neighbours.
- `longestSpan()` returns the largest number minus the smallest, found with `std::min_element` and `std::max_element`.
- Both throw if fewer than 2 numbers are stored.

The tests include a span of 10,000 random numbers.
```
 === test 1: basic functionality === 
Shortest span: 2
Longest span: 14

 === test 2: exception handling === 
Added 3 numbers successfully
Caught expected exception: Span is already full
Caught expeced exception: No span can be found (need at least 2 numbers)
...
 === test3 : large span (10k numbers) === 
added 10k random numbers
Shortest span: 30
Longest span: 2147296153
```

### ex02 – Mutated abomination
`std::stack` is one of the few STL containers that can't be iterated. `MutantStack<T>` inherits from `std::stack<T>` and adds `begin()` and `end()`. A `std::stack` keeps its elements in a protected member container, `c` (a `std::deque` by default), so `MutantStack` simply returns that container's iterators.

Running the subject's test with `MutantStack` and then with a `std::list` gives the same output:
```
=== test ===
17
1
5
3
5
737
0

 === comparison with std::list ===
17
1
5
3
5
737
0
```

## Compile and Run
Each exercise has its own `Makefile`. `cd` into the folder and run `make`. The `clean`, `fclean` and `re` targets are also available.

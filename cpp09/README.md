# CPP09

> 42 Common Core · Rank 05 · Subject: [en.subject.pdf](en.subject.pdf)

## Introduction
The last C++ module is about the **STL**. Each exercise is a small program that must use STL containers, and a container used in one exercise can't be used again in the next ones:

| Exercise | Program | Container(s) |
|---|---|---|
| ex00 | `btc` | `std::map` |
| ex01 | `RPN` | `std::stack` (on top of a `std::list`) |
| ex02 | `PmergeMe` | `std::vector` and `std::deque` |

All the code is written in **C++98** and compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

## Exercises
| Folder | Subject title | Executable | Status |
|---|---|---|---|
| [ex00](ex00) | Bitcoin Exchange | `btc` | Done |
| [ex01](ex01) | Reverse Polish Notation | `RPN` | Done |
| [ex02](ex02) | PmergeMe | `PmergeMe` | Done |

### ex00 – Bitcoin Exchange
```bash
./btc <input file>
```
Loads the bitcoin price history from `data.csv` into a `std::map<std::string, float>` (date → rate). Then it reads the input file, where each line is `date | value`, and prints the value multiplied by the rate on that date.

If the date is not in the database, it uses the **closest earlier date**, found with `std::map::lower_bound`. A valid value is a float or a positive integer between 0 and 1000.

```bash
cd ex00 && make
./btc error2.txt
```

Result:
```
date | value
2011-01-03  => 3 = 0.9
2011-01-03  => 2 = 0.6
2011-01-03  => 1 = 0.3
2011-01-03  => 1.2 = 0.36
2011-01-09  => 1 = 0.32
wrong quantity
wrong format: |
2012-01-11  => 1 = 7.1
wrong quantity
```

| Message | Cause |
|---|---|
| `Need one input file` | Not exactly one argument |
| `Couldn't open <file>` | The input file does not exist or can't be read |
| `wrong format: \|` | The line has no `\|` separator |
| `wrong date` | The date is not a real `YYYY-MM-DD` date (for example `2011-13-01` or `2012-02-30`) |
| `wrong quantity` | The value is negative, above 1000 or not a number |
| `Date too early: <date>` | The date is before the first date in the database |
| `wrong database` | `data.csv` is badly formatted |

The folder has test files to try: `input.csv`, `correct.txt` (only valid lines), `error1.txt` (all kinds of bad dates and values) and `error2.txt` (the subject's example).

### ex01 – Reverse Polish Notation
```bash
./RPN "<expression>"
```
Evaluates an expression in Reverse Polish Notation, where the operator comes after its two operands. Numbers are single digits below 10, and the operators are `+ - * /`. Each number is pushed onto a `std::stack`. Each operator pops two numbers, applies the operation and pushes the result back.
```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "7 7 * 7 -"
./RPN "1 2 * 2 / 2 * 2 4 - +"
./RPN "(1 + 1)"
```

Result:
```
42
42
0
Error: Wrong characters
```
Other errors: `Error: Unfinished number`, `Error: not enough number` and `Error: division by 0`.

### ex02 – PmergeMe
```bash
./PmergeMe <positive integers...>
```
Sorts a sequence of positive integers with the **Ford–Johnson merge-insert sort**. The algorithm is written twice, once with `std::vector` and once with `std::deque`, and both are timed:
1. Pair up the numbers and put the larger of each pair in a "winners" chain.
2. Sort the winners recursively with the same algorithm.
3. Insert the smaller numbers ("losers") into the sorted chain with binary search, in the order given by the **Jacobsthal numbers**, which keeps the number of comparisons low.

```bash
cd ex02 && make
./PmergeMe 3 5 9 7 4
./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
./PmergeMe "-1" "2"
```

Result:
```
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::vector : 19 us
Time to process a range of 5 elements with std::deque : 43 us

Before: 61037 17499 31069 91991 27803 26604 70237 61145 85856 75064 ...
After: 33 63 117 120 208 231 268 295 302 383 458 571 602 656 728 738 ...
Time to process a range of 3000 elements with std::vector : 250414 us
Time to process a range of 3000 elements with std::deque : 642538 us

Error: Wrong Input
```

## Compile and Run
Each exercise has its own `Makefile`. `cd` into the folder and run `make`. The `clean`, `fclean` and `re` targets are also available.

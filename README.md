# Push Swap

*This project has been created as part of the 42 curriculum by arde-ass and ccolnat.*

## Description

The Push swap project is a simple yet highly structured algorithmic challenge: you need to sort data. The goal is to write a C program named `push_swap` that calculates and displays the smallest possible sequence of instructions to sort given integers.

We have two stacks at our disposal, named `a` and `b`, and a limited set of instructions to manipulate them. At the start, stack `a` contains random and unique integers, and stack `b` is empty. The goal is to sort the numbers in stack `a` in ascending order using as few operations as possible.

## Technical Choices

To tackle this challenge, we opted for a **circular doubly linked list** to represent our stacks.

- **Doubly linked:** Enables bidirectional traversal, greatly facilitating insertion and extraction during transfer operations between stacks.
- **Circular:** Makes rotation and reverse rotation operations extremely efficient (O(1) complexity) by simply moving the head pointer, without having to traverse the entire stack.
- **Indexing:** Raw values are pre-converted into indexes (from 0 to N-1) to simplify comparisons and optimize algorithms on large volumes of data.

## Instruction Set

### Swap — `sa`, `sb`, `ss`

Swaps the two top elements of a stack. `ss` performs `sa` and `sb` simultaneously.

```
Before          After sa
 a     b         a     b
[2]   [ ]       [5]   [ ]
[5]             [2]
[1]             [1]
[4]             [4]
```

### Push — `pa`, `pb`

Moves the top element of one stack to the top of the other.
`pb` pushes from `a` to `b`, `pa` pushes from `b` to `a`.

```
Before        After pb       After pa
 a     b       a     b        a     b
[2]   [ ]     [5]   [2]      [2]   [ ]
[5]           [1]            [5]
[1]           [4]            [1]
[4]                          [4]
```

### Rotate — `ra`, `rb`, `rr`

Shifts all elements upward. The first element becomes the last.
`rr` performs `ra` and `rb` simultaneously.

```
Before        After ra
 a             a
[2]           [5]
[5]           [1]
[1]           [4]
[4]           [2]
```

### Reverse Rotate — `rra`, `rrb`, `rrr`

Shifts all elements downward. The last element becomes the first.
`rrr` performs `rra` and `rrb` simultaneously.

```
Before        After rra
 a             a
[2]           [4]
[5]           [2]
[1]           [5]
[4]           [1]
```

## Algorithms Used

*(To be completed: Detail here your logical implementation for sorting 3 numbers, 5 numbers, and your main algorithm for 100/500 numbers, such as Radix Sort or a Chunk-based algorithm).*

## Instructions

### Compilation

A `Makefile` is provided to compile source files with the `-Wall`, `-Wextra`, and `-Werror` flags using the `cc` compiler.

```bash
make
```

### Execution

The program takes the list of integers to sort as arguments (the first argument being the top of stack `a`).

```bash
./push_swap 4 67 3 87 23
```

## Resources

- **Documentation:** *(To be completed: Add here your links to tutorials on doubly linked lists or sorting algorithms you have studied).*
- **AI Usage:** Artificial intelligence tools were used during this project to conceptualize the structure of this README, clarify the theoretical workings of a circular doubly linked list, and simplify the notion of algorithmic complexity related to stack manipulations.

# push_swap

A C program that sorts a list of integers using two stacks and a limited set of operations, aiming to minimize the number of moves.

## Compile

```bash
make
```

This will generate the executable `push_swap`.

## Usage

Run the program with a list of integers as arguments:

```bash
./push_swap 3 2 1
```

Arguments can also be provided as a single, space-separated string:

```bash
./push_swap "3 2 1"
```

The program outputs a list of operations (one per line) that will sort stack A in ascending order.

To count the number of operations:

```bash
./push_swap 3 2 1 | wc -l
```

## Notes

- Stack `A` is initialized with the given integers
- Stack `B` starts empty
- Only a restricted set of operations is allowed:
 - swaps (`sa`, `sb`, `ss`)
 - pushes (`pa`, `pb`)
 - rotations (`ra`, `rb`, `rr`)
 - reverse rotations (`rra`, `rrb`, `rrr`)
- The goal is to sort stack A using as few operations as possible

## Implementation notes

- Input supports both multiple arguments and space-separated values in a single argument
- Whitespace, optional sign (`+`/`-`), and numeric format are validated
- Input is checked for:
 - non-numeric values
 - integer overflow and underflow
 - duplicate numbers
- Small input sizes (2-5 numbers) are handled with optimized strategies
- Larger inputs are sorted using a radix-based approach (indexing values and sorting by bits)
- The implementation primarily relies on operations `pa`, `pb`, `ra`, `rra`, and `sa`
- The program outputs nothing if the input is already sorted or empty

## Context

This project was implemented as part of the 42 Network curriculum.
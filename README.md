# PUSH_SWAP

## Summary

- Two stacks A and B are given.
- Initially, A is filled with numbers (no redundancy)
- The goal is to sort the numbers in A through the appropriate "calculation".
- The operations available for the task are: (first element == most recently inserted element)
- pa : transfer the first element of stack B to a.
- pb : transfer the first element of stack A to b.
- sa : The first and second elements of stack A switch places.
- sb : the first and second elements of stack B switch places.
- ss : run sa and sb at the same time.
- r : Rotates elements in stack A (first element last)
- rb : rotate the element in stack B (first element last)
- rr : run ra and rb at the same time.
- rra: rotate the element in stack A (first element last)
- rrb : rotate the element in stack B (first element last)
- rrr: Run rra and rrb at the same time.

## The Project
- Create two programs: checker and push_swap.

- The checker program reads a random list of integers from the stdin, stores them, and checks to see if they are sorted.

- The push_swap program calculates the moves to sort the integers – pushing, popping, swapping and rotating them between stack a and stack b – and displays those directions on the stdout.

- You can pipe push_swap into checker, and checker will verify that push_swap's instructions were successful.

- Both programs must mandatorily parse input for errors, including empty strings, no parameters, non-numeric parameters, duplicates, and invalid/non-existent instructions.

- Push_Swap must conform to the 42 Norm. Using normal libc functions is strictly forbidden. Students are however, allowed to use: write, read, malloc, free, exit. It must not have any memory leaks. Errors must be handled carefully. In no way can it quit in an unexpected manner (segmentation fault, bus error, double free, etc).
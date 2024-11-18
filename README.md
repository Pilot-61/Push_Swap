# Push Swap 📊

## 🎯 Project Overview
Push Swap is a sorting algorithm challenge where you must sort a stack of integers using a limited set of stack manipulation instructions with minimal operations.

## 🛠 Project Rules
- Two stacks: `a` and `b`
- Goal: Sort stack `a` in ascending order
- Allowed operations:
  - `sa`: Swap top two elements of stack a
  - `sb`: Swap top two elements of stack b
  - `ss`: Swap top elements of both stacks
  - `pa`: Push top element from b to a
  - `pb`: Push top element from a to b
  - `ra`: Rotate stack a up
  - `rb`: Rotate stack b up
  - `rr`: Rotate both stacks up
  - `rra`: Reverse rotate stack a
  - `rrb`: Reverse rotate stack b
  - `rrr`: Reverse rotate both stacks

## 📦 Compilation
```bash
make           # Compile push_swap
```

## 🚀 Usage
```bash
# Sort integers
./push_swap 3 2 1 0 5

# Check sorting with checker
./push_swap 3 2 1 0 5 | ./checker 3 2 1 0 5
```

## 🎢 Benchmarks
- 100 numbers: < 700 operations
- 500 numbers: < 5500 operations

## 📋 Requirements
- C programming language
- No global variables
- Minimal number of sorting operations
- Error handling for invalid inputs

## 🔍 Key Challenges
- Implement efficient sorting algorithm
- Minimize number of stack operations
- Handle edge cases and input validation

## 🏆 Bonus
- Implement a `checker` program to validate sorting instructions

## 👥 Authors
- Mohammed Amine Es-salhi

# Backtracking Template (LeetCode Revision)

## Core Idea

Backtracking = **Do → Recurse → Undo**

At every step:

1. Make a choice.
2. Explore further.
3. Undo the choice and try another path.

---

## Universal Template

```cpp
void solve(arguments..., string& current_state, vector<string>& ans) {

    // Base Case
    if (stop_condition) {
        ans.push_back(current_state);
        return;
    }

    // Choice 1
    if (choice1_is_valid) {
        current_state.push_back(option1); // Do
        solve(..., current_state, ans);   // Recurse
        current_state.pop_back();         // Undo
    }

    // Choice 2
    if (choice2_is_valid) {
        current_state.push_back(option2); // Do
        solve(..., current_state, ans);   // Recurse
        current_state.pop_back();         // Undo
    }
}
```

---

# Generic Vector Template

```cpp
void solve(vector<int>& nums,
           vector<int>& path,
           vector<vector<int>>& ans) {

    if (base_case) {
        ans.push_back(path);
        return;
    }

    for (choice in available_choices) {

        if (!valid_choice)
            continue;

        path.push_back(choice);   // Do

        solve(nums, path, ans);   // Recurse

        path.pop_back();          // Undo
    }
}
```

---

# How to Identify Backtracking

If question says:

✅ Generate all possibilities

✅ Find all combinations

✅ Find all subsets

✅ Find all permutations

✅ N-Queens

✅ Sudoku Solver

✅ Word Search

Then think:

> "Try a choice, explore, undo the choice."

---

# Must-Do LeetCode Questions

## Easy

### 1. Subsets

* LC 78
* Pattern: Include / Exclude

```cpp
Take
Not Take
```

---

### 2. Letter Combinations of Phone Number

* LC 17
* Pattern: Multiple Choices

---

## Medium

### 3. Combination Sum

* LC 39
* Pattern: Pick Unlimited Times

---

### 4. Combination Sum II

* LC 40
* Pattern: Duplicates Handling

```cpp
if(i > start && nums[i] == nums[i-1])
    continue;
```

---

### 5. Permutations

* LC 46
* Pattern: Used Array

```cpp
vector<bool> used(n,false);
```

---

### 6. Permutations II

* LC 47
* Pattern: Permutations + Duplicates

---

### 7. Subsets II

* LC 90
* Pattern: Subsets + Duplicates

---

### 8. Palindrome Partitioning

* LC 131
* Pattern: Partition String

---

### 9. Restore IP Addresses

* LC 93
* Pattern: String Partition

---

### 10. Word Search

* LC 79
* Pattern: Grid Backtracking

```cpp
Up
Down
Left
Right
```

---

## Hard

### 11. N-Queens

* LC 51
* Most Important Backtracking Problem

Learn:

* Column check
* Diagonal check

---

### 12. N-Queens II

* LC 52

---

### 13. Sudoku Solver

* LC 37

Classic Interview Question.

---

# Backtracking Cheat Sheet

## Subsets

```cpp
Take
Not Take
```

---

## Permutations

```cpp
for(all elements)
```

Use visited array.

---

## Combination Sum

```cpp
Pick
Stay on same index
```

---

## Combination Sum II

```cpp
Pick
Move to next index
Skip duplicates
```

---

## Grid Problems

```cpp
Mark visited
Explore 4 directions
Unmark visited
```

---

# Golden Formula

```cpp
Choose
Explore
Unchoose
```

or

```cpp
Do
Recurse
Undo
```

This single pattern solves 90% of Backtracking questions on LeetCode.

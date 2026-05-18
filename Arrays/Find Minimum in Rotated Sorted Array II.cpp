# LeetCode 154 - Find Minimum in Rotated Sorted Array II (C++)

This repository contains an optimized C++ solution for LeetCode Problem 154:
**Find Minimum in Rotated Sorted Array II**

## Problem Statement

Suppose an array of length `n` sorted in ascending order is rotated between `1` and `n` times.

Find the minimum element in the array.

Duplicates may exist in the array.

## Example

Input:
[2,2,2,0,1]

Output:
0

## Approach

We use **Binary Search** to efficiently locate the minimum element.

### Key Observations

- If `nums[mid] > nums[right]`
  → Minimum lies in the right half.

- If `nums[mid] < nums[right]`
  → Minimum lies in the left half including `mid`.

- If duplicates exist:
  → Reduce search space using `right--`.

## Time Complexity

- Average Case: `O(log n)`
- Worst Case: `O(n)`

## Space Complexity

- `O(1)`

## Topics

- Binary Search
- Rotated Sorted Array
- LeetCode
- C++
- DSA
- Algorithms

## Author

Saurabh Singh

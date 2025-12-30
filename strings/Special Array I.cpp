/*
====================================================
Problem Name : Special Array I
Platform     : LeetCode
Difficulty   : Easy

Problem Link :
https://leetcode.com/problems/special-array-i/

----------------------------------------------------
Problem Description:
You are given an array of integers `nums`.

An array is considered **special** if:
- For every adjacent pair of elements,
  one element is even and the other is odd.

In other words, all adjacent elements must have
**different parity**.

Return `true` if the array is special, otherwise return `false`.

----------------------------------------------------
Examples:

Input:
nums = [1, 2, 3, 4]
Output:
true
Explanation:
Parity alternates for all adjacent elements.

Input:
nums = [2, 4, 6]
Output:
false
Explanation:
All adjacent elements are even.

----------------------------------------------------
Approach Used:
1. If the array has only one element, it is trivially special.
2. Traverse the array from index 1 to n-1.
3. For each adjacent pair:
   - If both numbers have the same parity (both even or both odd),
     return false immediately.
4. If the loop completes without failure, return true.

----------------------------------------------------
Time Complexity:
O(n), where n is the size of the array.

Space Complexity:
O(1), constant extra space.

----------------------------------------------------
Author Notes:
- Simple parity check using modulo operation.
- Uses early exit for efficiency.
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {

        int x = nums.size();
        if (x == 1) {
            return true;
        }

        for (int i = 1; i < x; i++) {
            int a = nums[i];
            int b = nums[i - 1];

            // If both have same parity, array is not special
            if ((a % 2) == (b % 2)) {
                return false;
            }
        }

        return true;
    }
};

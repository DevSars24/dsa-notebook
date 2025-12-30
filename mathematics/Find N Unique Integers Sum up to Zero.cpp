/*
====================================================
Problem: Find N Unique Integers Sum up to Zero
Platform: LeetCode
Difficulty: Easy
Link: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

Author: Saurabh Singh
====================================================

Problem Statement:
Given an integer n, return any array containing n unique integers
such that their sum is equal to 0.

----------------------------------------------------
Examples:
Input: n = 5
Output: [1, -1, 2, -2, 0]

Input: n = 3
Output: [1, -1, 0]

----------------------------------------------------
Intuition:
To make the sum of numbers equal to zero:
- Always add numbers in pairs (x, -x)
- Each pair contributes 0 to the sum
- If n is odd, one element can be 0

This guarantees:
- All elements are unique
- Total sum is zero

----------------------------------------------------
Approach:
1. Initialize a vector of size n with all elements as 0
2. Traverse the array in steps of 2
3. Fill pairs as (i+1) and -(i+1)
4. If n is odd, the last element remains 0 automatically

----------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
----------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n, 0);

        // Fill pairs of positive and negative numbers
        for (int i = 0; i + 1 < n; i += 2) {
            ans[i] = i + 1;
            ans[i + 1] = -(i + 1);
        }

        // If n is odd, the last element remains 0
        return ans;
    }
};

/*
----------------------------------------------------
Why this works:
- Each (x, -x) pair cancels out
- Zero handles the odd-length case
- No duplicates are introduced
----------------------------------------------------
*/

/*
============================================================
LeetCode 1673
Find the Most Competitive Subsequence
============================================================

Platform   : LeetCode
Difficulty : Medium
Link       : https://leetcode.com/problems/find-the-most-competitive-subsequence/

------------------------------------------------------------
Problem Statement (Short):
------------------------------------------------------------
Given an integer array nums and an integer k, return the
most competitive subsequence of nums of size k.

A subsequence is more competitive if at the first position
where they differ, it has a smaller value.

------------------------------------------------------------
Core Idea / Pattern:
------------------------------------------------------------
This is a GREEDY + MONOTONIC STACK problem.

Goal:
- Build a subsequence of length exactly k
- Lexicographically smallest possible
- Order must be preserved

------------------------------------------------------------
Key Intuition:
------------------------------------------------------------
We remove (pop) larger elements from the stack if:
1) Current element is smaller
2) And even after popping, we can still form a subsequence
   of length k using remaining elements

We NEVER pop if doing so makes it impossible to reach size k.

------------------------------------------------------------
Golden Condition (Most Important Line):
------------------------------------------------------------
(st.size() - 1) + (n - i) >= k

Meaning:
If we pop now, do we still have enough elements left
to build a subsequence of length k?

------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {

        int n = nums.size();
        stack<int> st;

        /*
        ----------------------------------------------------
        Step 1: Iterate through the array
        ----------------------------------------------------
        For each element:
        - Remove larger elements from stack if allowed
        - Push current element if stack size < k
        */

        for (int i = 0; i < n; i++) {

            // Greedy popping
            while (!st.empty() &&
                   st.top() > nums[i] &&
                   (st.size() - 1 + (n - i)) >= k) {
                st.pop();
            }

            // Push only if we still need elements
            if (st.size() < k) {
                st.push(nums[i]);
            }
        }

        /*
        ----------------------------------------------------
        Step 2: Build result from stack
        ----------------------------------------------------
        Stack stores elements in reverse order
        */

        vector<int> ans(k);
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};

/*
====================================================
Problem   : Single Number
Platform  : LeetCode
Link      : https://leetcode.com/problems/single-number/
Author    : Saurabh Singh Rajput
Language  : C++
====================================================

Problem Statement:
Given a non-empty array of integers nums, every element appears twice except for one.
Find that single one.

Approach Used:
1. Calculate the sum of all elements in the array.
2. Insert all elements into an unordered_set to keep only unique values.
3. Calculate the sum of unique elements.
4. The single number can be found using:
   single = 2 * (sum of unique elements) - (sum of all elements)

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_set<int> st;
        int sumAll = 0;
        int sumUnique = 0;

        // Sum of all elements
        for(int x : nums){
            sumAll += x;
            st.insert(x);
        }

        // Sum of unique elements
        for(int x : st){
            sumUnique += x;
        }

        return (2 * sumUnique) - sumAll;
    }
};

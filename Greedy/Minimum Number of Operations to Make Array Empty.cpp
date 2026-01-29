/*
------------------------------------------------------------
Platform : LeetCode
Problem  : Minimum Number of Operations to Make Array Empty
Link     : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
------------------------------------------------------------

Problem Summary:
You are given an integer array nums.
In one operation, you can remove:
- Either 2 equal elements, or
- 3 equal elements.

Return the minimum number of operations required to make the array empty.
If it is not possible, return -1.

------------------------------------------------------------
Approach:
1. Count the frequency of each element using unordered_map.
2. If any element appears only once, return -1 (cannot remove single element).
3. For each frequency:
   - Minimum operations = ceil(freq / 3)
4. Sum all operations and return the result.

------------------------------------------------------------
Time Complexity  : O(n)
Space Complexity : O(n)
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {

        unordered_map<int, int> mp;

        // Count frequency of each number
        for (int num : nums) {
            mp[num]++;
        }

        int result = 0;

        // Calculate minimum operations
        for (auto &it : mp) {
            int freq = it.second;

            // If frequency is 1, impossible to remove
            if (freq == 1) {
                return -1;
            }

            // Minimum operations using groups of 2 or 3
            result += ceil((double)freq / 3);
        }

        return result;
    }
};

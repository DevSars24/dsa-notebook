/*
====================================================
LeetCode 930. Binary Subarrays With Sum
Link: https://leetcode.com/problems/binary-subarrays-with-sum/

----------------------------------------------------
PROBLEM STATEMENT:
----------------------------------------------------
You are given a binary array nums (containing only 0s and 1s)
and an integer goal.

Return the number of non-empty subarrays with sum exactly equal to goal.

----------------------------------------------------
EXAMPLE:
----------------------------------------------------
Input: nums = [1,0,1,0,1], goal = 2
Output: 4

Valid subarrays:
[1,0,1]
[1,0,1]
[0,1,0,1]
[1,0,1]

----------------------------------------------------
KEY OBSERVATION:
----------------------------------------------------
The array contains ONLY 0s and 1s.
This makes Sliding Window applicable.

----------------------------------------------------
CORE INTUITION (VERY IMPORTANT):
----------------------------------------------------
Counting subarrays with EXACT sum = goal is hard directly.

But we can convert it into an easier problem:

subarrays with sum == goal
= subarrays with sum <= goal
- subarrays with sum <= (goal - 1)

This trick works perfectly for non-negative arrays.

----------------------------------------------------
WHY THIS WORKS?
----------------------------------------------------
- atMost(goal) gives all subarrays having sum 0 to goal
- atMost(goal - 1) gives all subarrays having sum 0 to goal-1
- Their difference leaves ONLY subarrays with sum exactly = goal

----------------------------------------------------
APPROACH:
----------------------------------------------------
1. Write a helper function atMost(nums, goal)
2. Use sliding window to count subarrays with sum <= goal
3. Final answer:
   atMost(nums, goal) - atMost(nums, goal - 1)

----------------------------------------------------
TIME COMPLEXITY:
----------------------------------------------------
O(n)

----------------------------------------------------
SPACE COMPLEXITY:
----------------------------------------------------
O(1)

====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Function to count subarrays with sum <= goal
    int atMost(vector<int>& nums, int goal) {
        
        // If goal is negative, no valid subarray exists
        if (goal < 0) return 0;

        int i = 0;        // left pointer
        int sum = 0;      // current window sum
        int count = 0;    // number of valid subarrays

        // Expand window using j pointer
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];

            // Shrink window until sum <= goal
            while (sum > goal) {
                sum -= nums[i];
                i++;
            }

            // Number of subarrays ending at j
            count += (j - i + 1);
        }

        return count;
    }

    // Main function
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

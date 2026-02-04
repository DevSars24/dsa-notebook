/*
------------------------------------------------------------
Problem: LeetCode 53 - Maximum Subarray
Link: https://leetcode.com/problems/maximum-subarray/

Author: Saurabh Singh
Approach: Kadane's Algorithm
Difficulty: Medium
------------------------------------------------------------

Problem Statement:
Given an integer array nums, find the contiguous subarray
(containing at least one number) which has the largest sum
and return its sum.

------------------------------------------------------------
Approach Explanation:
Kadane's Algorithm works by maintaining:
1. currSum → Maximum subarray sum ending at current index
2. maxSum  → Overall maximum subarray sum found so far

At each index:
- Either start a new subarray from nums[i]
- Or extend the previous subarray

Formula:
currSum = max(nums[i], currSum + nums[i])
maxSum  = max(maxSum, currSum)

------------------------------------------------------------
Time Complexity:  O(n)
Space Complexity: O(1)
------------------------------------------------------------
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int currSum = nums[0];
        int maxSum  = nums[0];

        for (int i = 1; i < n; i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};

/*
------------------------------------------------------------
Example:
Input:  [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation:
Subarray [4, -1, 2, 1] has the largest sum = 6
------------------------------------------------------------
*/

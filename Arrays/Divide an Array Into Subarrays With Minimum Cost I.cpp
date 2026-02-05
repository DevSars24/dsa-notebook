/*
------------------------------------------------------------
Problem: Divide an Array Into Subarrays With Minimum Cost I
Platform: LeetCode
Link: https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/
------------------------------------------------------------

🧠 Problem Summary:
You are given an integer array `nums`.
The cost is calculated by:
- Always including `nums[0]`
- Selecting the two smallest elements from the remaining array
Return the minimum possible total cost.

------------------------------------------------------------
💡 Approach:
1. Store `nums[0]` as the base score.
2. Traverse the array from index 1 to n-1.
3. Track the smallest (`firstMin`) and second smallest (`secondMin`) values.
4. Add them to the base score.

This greedy approach works because:
- `nums[0]` is mandatory
- To minimize total cost, we must choose the two smallest remaining values

------------------------------------------------------------
⏱ Time Complexity:
O(n) — single traversal of the array

🧮 Space Complexity:
O(1) — constant extra space

------------------------------------------------------------
*/

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        // Base score must include the first element
        int score = nums[0];

        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        // Find two smallest elements from index 1 onwards
        for (int i = 1; i < n; i++) {
            if (nums[i] < firstMin) {
                secondMin = firstMin;
                firstMin = nums[i];
            } 
            else if (nums[i] < secondMin) {
                secondMin = nums[i];
            }
        }

        return score + firstMin + secondMin;
    }
};

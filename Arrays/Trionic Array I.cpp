
/*
=====================================================
Problem: Trionic Array I
Platform: LeetCode
Language: C++
Author: Saurabh Singh
Status: Accepted ✅
=====================================================

🧠 Problem Insight:
A Trionic Array is an array that:
1. Strictly increases
2. Then strictly decreases
3. Then strictly increases again

Each segment must have at least one element,
and the turning points must NOT be at the ends.

-----------------------------------------------------
Approach:
- Traverse the array using a pointer `i`
- Step 1: Move while array is strictly increasing
- Step 2: Move while array is strictly decreasing
- Step 3: Move while array is strictly increasing
- Ensure:
  - Transitions happen inside the array (not at index 0 or n-1)
  - Entire array is consumed at the end

-----------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
-----------------------------------------------------
*/

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int i = 0;

        // First increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        if (i == 0 || i == n - 1) return false;

        // Then decreasing
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }
        if (i == n - 1) return false;

        // Final increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        return i == n - 1;
    }
};

/*
--------------------------------------------------------------------
LeetCode Problem: Minimum Pair Removal to Sort Array I
Link: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/

Difficulty: Medium
--------------------------------------------------------------------

🧠 Intuition:
We are allowed to repeatedly remove a pair of adjacent elements and
replace them with their sum.

Goal:
- Perform the minimum number of such operations so that the array
  becomes sorted in non-decreasing order.

Key idea:
- As long as the array is not sorted, we must perform an operation.
- To minimize operations, we greedily merge the adjacent pair
  with the **minimum sum**.
- Merging the smallest adjacent pair causes the least disturbance
  to the array order and helps the array move toward being sorted.

This greedy strategy works because:
- Smaller merges are less likely to introduce large inversions.
- Each operation reduces the array size by 1.
- Eventually, the array becomes sorted.

--------------------------------------------------------------------

🛠️ Approach:
1. While the array is not sorted:
   - Find the index of the adjacent pair with minimum sum.
   - Merge the pair (replace nums[i] with nums[i] + nums[i+1]).
   - Remove nums[i+1] from the array.
   - Increment operation count.
2. Return the total number of operations.

--------------------------------------------------------------------

⏱️ Time Complexity:
- O(n²) in the worst case
  (each iteration scans the array and reduces size by 1).

🧠 Space Complexity:
- O(1) extra space (in-place operations).

--------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to find index of adjacent pair with minimum sum
    int minPairSumIndex(vector<int>& nums) {
        int idx = 0;
        int minSum = nums[0] + nums[1];

        for (int i = 1; i < nums.size() - 1; i++) {
            int currSum = nums[i] + nums[i + 1];
            if (currSum < minSum) {
                minSum = currSum;
                idx = i;
            }
        }
        return idx;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        // Continue until the array becomes sorted
        while (!is_sorted(nums.begin(), nums.end())) {
            int index = minPairSumIndex(nums);

            // Merge the minimum sum adjacent pair
            nums[index] = nums[index] + nums[index + 1];
            nums.erase(nums.begin() + index + 1);

            operations++;
        }

        return operations;
    }
};

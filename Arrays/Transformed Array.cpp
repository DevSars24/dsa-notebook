/*
------------------------------------------------------------
Problem: Transformed Array
Platform: LeetCode
Link: https://leetcode.com/problems/transformed-array/
------------------------------------------------------------

🧠 Problem Summary:
You are given an integer array `nums` of length `n`.
For each index `i`, you need to:
- Move `nums[i]` steps forward (if positive)
- Or backward (if negative)
- Circularly within the array
Then place the value found at that position into a new array.

Return the transformed array.

------------------------------------------------------------
💡 Approach:
1. Let `n` be the size of the array.
2. For each index `i`:
   - Compute shift = nums[i] % n
   - New index = (i + shift) % n
   - Handle negative indices by adding `n`
3. Store `nums[newIndex]` into result[i]

This ensures:
- Circular movement
- No out-of-bounds access
- Efficient computation

------------------------------------------------------------
⏱ Time Complexity:
O(n) — single pass through the array

🧮 Space Complexity:
O(n) — extra array for result

------------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();

        // Result array initialized with 0
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {
            int shift = nums[i] % n;
            int newIndex = (i + shift) % n;

            // Handle negative circular index
            if (newIndex < 0) {
                newIndex += n;
            }

            result[i] = nums[newIndex];
        }

        return result;
    }
};

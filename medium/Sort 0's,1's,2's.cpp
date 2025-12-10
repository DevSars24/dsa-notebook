/*
================================================================================
🧩 Problem: 75. Sort Colors (LeetCode)
================================================================================

Given an array `nums` containing only values 0, 1, and 2, sort them in-place so 
that:
    0 → Red
    1 → White
    2 → Blue
are grouped together in the order: [0s, 1s, 2s]

⚠️ Constraints:
- You MUST solve this without using any library sort function.
- Only one pass allowed (O(n))
- Constant extra space (O(1))

This is a classic **Dutch National Flag Problem** by Edsger Dijkstra.

--------------------------------------------------------------------------------
🎯 Goal:
Input : [2, 0, 2, 1, 1, 0]
Output: [0, 0, 1, 1, 2, 2]
--------------------------------------------------------------------------------

📌 Algorithm Used: Dutch National Flag Algorithm (3-pointer technique)

We maintain 3 regions:
    i → boundary for 0's  (left side)
    j → current index
    k → boundary for 2's  (right side)

Rules:
1️⃣ nums[j] == 1 → just move j forward  
2️⃣ nums[j] == 2 → swap nums[j] with nums[k], then k--  
3️⃣ nums[j] == 0 → swap nums[j] with nums[i], then i++, j++

We stop when j > k.


================================================================================
🔍 DRY RUN (Example: nums = [2, 0, 1])
================================================================================

Initial:
nums = [2, 0, 1]
i = 0, j = 0, k = 2

Step 1: nums[j] = 2  
→ swap(nums[0], nums[2]) → [1,0,2]  
→ k-- → k = 1  
(j stays because swapped value must be rechecked)

Step 2: nums[j] = 1  
→ j++ → j = 1  

Step 3: nums[j] = 0  
→ swap(nums[1], nums[0]) → [0,1,2]  
→ i = 1, j = 2

Now j > k → STOP

Final Output: [0, 1, 2]


================================================================================
⏱️ Time Complexity:  O(n)
💾 Space Complexity: O(1)
================================================================================
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int i = 0;                  // marks the boundary for 0's
        int j = 0;                  // current pointer
        int k = nums.size() - 1;    // marks the boundary for 2's

        while (j <= k) {

            if (nums[j] == 1) {
                // 1 is already in the correct middle section
                j++;

            } else if (nums[j] == 2) {
                // 2 should be moved to the end region
                swap(nums[j], nums[k]);
                k--;

            } else {
                // nums[j] == 0 → Move to the front region
                swap(nums[j], nums[i]);
                i++;
                j++;
            }
        }
    }
};

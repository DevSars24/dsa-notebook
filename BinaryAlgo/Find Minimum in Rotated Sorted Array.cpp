/*
===========================================================
LeetCode 153: Find Minimum in Rotated Sorted Array
===========================================================

Problem Statement:
------------------
Given a rotated sorted array with no duplicate elements,
find the minimum element in O(log n) time.

Example:
---------
Input:  [4,5,6,7,0,1,2]
Output: 0

-----------------------------------------------------------
Key Observations:
-----------------------------------------------------------
1. The original array was sorted in ascending order.
2. Rotation splits the array into two sorted parts.
3. The minimum element is the only element smaller than its previous.
4. Binary Search is optimal since array structure is sorted + rotated.

-----------------------------------------------------------
Core Idea (Binary Search on Answer):
-----------------------------------------------------------
We compare nums[mid] with nums[r]:

• If nums[mid] > nums[r]
  → Minimum lies in the RIGHT half (mid + 1 to r)

• Else
  → Minimum lies in LEFT half including mid (l to mid)

We shrink the search space until l == r,
which directly points to the minimum element.

-----------------------------------------------------------
Why Compare with nums[r]?
-----------------------------------------------------------
Because the rightmost element always belongs to the
"sorted tail" of the rotated array.

-----------------------------------------------------------
Algorithm Steps:
-----------------------------------------------------------
1. Initialize l = 0, r = n - 1
2. While l < r:
   a. mid = (l + r) / 2
   b. If nums[mid] > nums[r]:
        l = mid + 1
      Else:
        r = mid
3. Return nums[l]

-----------------------------------------------------------
Time & Space Complexity:
-----------------------------------------------------------
Time:  O(log n)
Space: O(1)

-----------------------------------------------------------
Accepted on LeetCode:
-----------------------------------------------------------
• 150 / 150 testcases passed
• Runtime: 0 ms (Beats 100%)
===========================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = (l + r) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};

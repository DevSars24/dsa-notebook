
/*
LeetCode Problem: Find First and Last Position of Element in Sorted Array
Problem Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Solution Approach:
I chose the binary search approach because:
1. The array is sorted, which is a perfect scenario for binary search (O(log n) time complexity)
2. We need to find both the first and last occurrence of the target
3. A single binary search won't suffice - we need two modified binary searches:
   - One to find the leftmost occurrence (first position)
   - One to find the rightmost occurrence (last position)

The key insight is to modify the standard binary search:
- For leftmost: When we find the target, instead of returning immediately, we continue searching in the left half
- For rightmost: When we find the target, we continue searching in the right half

This approach ensures O(log n) time complexity and O(1) space complexity.
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeftmost(nums, target);
        int right = findRightmost(nums, target);
        
        return {left, right};
    }
    
private:
    int findLeftmost(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int leftmost = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                leftmost = mid;
                // Continue searching in the left half for earlier occurrence
                right = mid - 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return leftmost;
    }
    
    int findRightmost(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int rightmost = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                rightmost = mid;
                // Continue searching in the right half for later occurrence
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return rightmost;
    }
};

/*
Example Usage:
vector<int> nums = {5,7,7,8,8,10};
int target = 8;
Solution sol;
vector<int> result = sol.searchRange(nums, target); // Returns [3, 4]

Time Complexity: O(log n) - Two binary searches
Space Complexity: O(1) - Only using constant extra space
*/

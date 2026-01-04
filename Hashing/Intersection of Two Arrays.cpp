/*
------------------------------------------------------------
Platform : LeetCode
Problem  : Intersection of Two Arrays
Link     : https://leetcode.com/problems/intersection-of-two-arrays/
Difficulty : Easy
------------------------------------------------------------

🧠 Problem Intuition:
Given two integer arrays, we need to return their intersection.
- Each element in the result must be unique.
- Order does not matter.

------------------------------------------------------------
🔍 Approach:
1. Insert all elements of nums1 into an unordered_set (s1)
2. Traverse nums2 and check:
   - If element exists in s1 → insert into another set (s2)
   - s2 ensures uniqueness in the final answer
3. Convert s2 into a vector and return

------------------------------------------------------------
⏱ Time Complexity:
- O(n + m)
  where n = size of nums1, m = size of nums2

💾 Space Complexity:
- O(n + m) in worst case (due to sets)

------------------------------------------------------------
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        int x = nums1.size();
        int y = nums2.size();

        vector<int> result;
        unordered_set<int> s1;
        unordered_set<int> s2;

        // Store elements of nums1
        for(int i = 0; i < x; i++){
            s1.insert(nums1[i]);
        }

        // Check intersection with nums2
        for(int i = 0; i < y; i++){
            if(s1.find(nums2[i]) != s1.end()){
                s2.insert(nums2[i]);
            }
        }

        // Convert set to vector
        for(auto it : s2){
            result.push_back(it);
        }

        return result;
    }
};

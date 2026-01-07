/*
---------------------------------------------------------
LeetCode 992: Subarrays with K Different Integers
Link:
https://leetcode.com/problems/subarrays-with-k-different-integers/

Problem:
Given an integer array nums and an integer k,
return the number of subarrays that contain exactly k distinct integers.

---------------------------------------------------------
INTUITION:

Counting subarrays with EXACTLY k distinct elements directly
using a single sliding window leads to overcounting.

Key Observation:
exactlyK = atMost(K) - atMost(K - 1)

Why?
- atMost(K): counts all subarrays having <= K distinct elements
- atMost(K-1): counts all subarrays having <= (K-1) distinct elements
- Subtracting removes extra subarrays and leaves only exactly K distinct ones

---------------------------------------------------------
FORMULA USED:

Exactly K Distinct Subarrays =
Number of subarrays with at most K distinct
- Number of subarrays with at most (K - 1) distinct

---------------------------------------------------------
APPROACH (Sliding Window + HashMap):

Use two pointers (i, j):
- Expand j to include elements
- Shrink i when distinct elements exceed k
- At each step, add (j - i + 1) to count
  → number of valid subarrays ending at j

---------------------------------------------------------
TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(N)
---------------------------------------------------------
*/

class Solution {
public:
    
    int atMostK(vector<int>& nums, int k) {
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        int count = 0;

        while (j < nums.size()) {
            mp[nums[j]]++;

            while (mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }

            // number of subarrays ending at j with <= k distinct
            count += (j - i + 1);
            j++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};

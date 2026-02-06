/*
    File: min_removal_to_balance_array.cpp
    Problem: Minimum Removals to Balance Array (LeetCode)
    Approach: Sorting + Sliding Window (Two Pointers)

    Idea:
    - Sort the array
    - Maintain a window [i...j] such that:
          nums[j] <= k * nums[i]
    - Maximize the window length
    - Answer = total elements - max window length

    Time Complexity: O(n log n)
    Space Complexity: O(1) (excluding sort space)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int maxLen = 0;

        for (int j = 0; j < n; j++) {
            // Shrink window if condition breaks
            while (i < j && (long long)nums[j] > (long long)k * nums[i]) {
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }

        // Minimum removals required
        return n - maxLen;
    }
};

/************************************************************
 *  Problem Name : Longest Balanced Subarray
 *  Platform     : LeetCode
 *  Difficulty   : Medium
 *
 *  Question Link:
 *  https://leetcode.com/problems/longest-balanced-subarray/
 *
 *  Author       : Saurabh Singh
 *  Language     : C++
 *  Date         : 10 Feb 2026
 *
 *  Description:
 *  Given an integer array nums, find the length of the
 *  longest contiguous subarray such that the number of
 *  DISTINCT even elements is equal to the number of
 *  DISTINCT odd elements.
 *
 *  ---------------------------------------------------------
 *  Approach (Brute Force + Hash Set):
 *  - Fix a starting index i
 *  - Expand the subarray till index j
 *  - Maintain two unordered sets:
 *      1. even -> stores distinct even numbers
 *      2. odd  -> stores distinct odd numbers
 *  - If size(even) == size(odd), update the answer
 *
 *  ---------------------------------------------------------
 *  Time Complexity:
 *  O(n^2)  -> checking all subarrays
 *
 *  Space Complexity:
 *  O(n)    -> unordered sets
 *
 *  Status:
 *  ✔ Accepted on LeetCode (999 / 999 test cases passed)
 ************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int n = nums.size();
        int result = 0;

        // Fix starting index
        for(int i = 0; i < n; i++) {

            unordered_set<int> even;
            unordered_set<int> odd;

            // Extend subarray
            for(int j = i; j < n; j++) {

                if(nums[j] % 2 == 0)
                    even.insert(nums[j]);
                else
                    odd.insert(nums[j]);

                // Balanced condition
                if(even.size() == odd.size()) {
                    result = max(result, j - i + 1);
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5, 6};
    cout << "Longest Balanced Subarray Length = "
         << sol.longestBalanced(nums) << endl;

    return 0;
}

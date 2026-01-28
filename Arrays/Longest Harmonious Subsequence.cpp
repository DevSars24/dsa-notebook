/*
====================================================
Platform   : LeetCode
Problem    : Longest Harmonious Subsequence
Link       : https://leetcode.com/problems/longest-harmonious-subsequence/

Difficulty : Easy
Language   : C++

----------------------------------------------------
Approach:
----------------------------------------------------
A harmonious subsequence is one where the difference
between the maximum and minimum elements is exactly 1.

Steps:
1. Use an unordered_map to store frequency of each number.
2. For every number x, check if x+1 exists in the map.
3. If yes, update the answer with:
      freq[x] + freq[x+1]
4. Take the maximum of all such valid pairs.

No sorting is required.
This is a common-sense frequency based problem.

----------------------------------------------------
Time Complexity  : O(n)
Space Complexity : O(n)
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int result = 0;

        // Step 1: Count frequencies
        for (int num : nums) {
            mp[num]++;
        }

        // Step 2: Check for harmonious pairs
        for (int num : nums) {
            if (mp.count(num + 1)) {
                result = max(result, mp[num] + mp[num + 1]);
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};

    Solution obj;
    cout << obj.findLHS(nums);

    return 0;
}

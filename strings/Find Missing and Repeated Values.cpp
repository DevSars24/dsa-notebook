/*
============================================================
LeetCode Problem 2965
Title     : Find Missing and Repeated Values
Difficulty: Easy
Platform  : LeetCode
Language  : C++

------------------------------------------------------------
Problem Summary:
Given an n x n grid containing numbers from 1 to n*n.
- One number appears twice (repeated)
- One number is missing

Return:
ans[0] -> repeated number
ans[1] -> missing number
------------------------------------------------------------

Approach (Frequency Counting):
1. Create a frequency array of size (n*n + 1)
2. Traverse the grid and count occurrences of each number
3. Traverse frequency array:
   - freq[i] == 2 → repeated number
   - freq[i] == 0 → missing number

------------------------------------------------------------
Time Complexity:
O(n^2)

Space Complexity:
O(n^2)  (frequency array)
============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();
        int N = n * n;

        vector<int> freq(N + 1, 0);
        vector<int> ans(2);

        // Count frequency of each number in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                freq[grid[i][j]]++;
            }
        }

        // Identify repeated and missing values
        for (int i = 1; i <= N; i++) {
            if (freq[i] == 2) ans[0] = i;  // repeated
            if (freq[i] == 0) ans[1] = i;  // missing
        }

        return ans;
    }
};

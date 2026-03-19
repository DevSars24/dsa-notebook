/*
===========================================================
🔗 Problem Link:
https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/

🧠 Problem Summary:
Given a grid of characters ('X', 'Y', '.'), count the number of submatrices
(from (0,0) to (i,j)) such that:
    - Number of 'X' == Number of 'Y'
    - And count > 0

-----------------------------------------------------------
💡 Intuition:
We use 2D Prefix Sum to track:
    - Number of 'X' till (i, j)
    - Number of 'Y' till (i, j)

At each cell (i, j), we compute:
    cumsumx[i][j] → total Xs in rectangle (0,0 → i,j)
    cumsumy[i][j] → total Ys in rectangle (0,0 → i,j)

Then simply check:
    if (X count == Y count && X > 0) → valid submatrix

-----------------------------------------------------------
⚙️ Approach:
1. Maintain two 2D prefix sum arrays:
   - cumsumx for 'X'
   - cumsumy for 'Y'

2. Build prefix sum using formula:
   curr = value
        + top
        + left
        - diagonal overlap

3. Check condition at every (i, j)

-----------------------------------------------------------
⏱️ Time Complexity: O(m * n)
📦 Space Complexity: O(m * n)

===========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Prefix sum arrays
        vector<vector<int>> cumsumx(m, vector<int>(n, 0));
        vector<vector<int>> cumsumy(m, vector<int>(n, 0));

        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                // Current cell contribution
                cumsumx[i][j] = (grid[i][j] == 'X');
                cumsumy[i][j] = (grid[i][j] == 'Y');

                // Add top
                if(i - 1 >= 0) {
                    cumsumx[i][j] += cumsumx[i-1][j];
                    cumsumy[i][j] += cumsumy[i-1][j];
                }

                // Add left
                if(j - 1 >= 0){
                    cumsumx[i][j] += cumsumx[i][j-1];
                    cumsumy[i][j] += cumsumy[i][j-1];
                }

                // Remove double counted overlap
                if(i - 1 >= 0 && j - 1 >= 0){
                    cumsumx[i][j] -= cumsumx[i-1][j-1];
                    cumsumy[i][j] -= cumsumy[i-1][j-1];
                }

                // Check condition
                if(cumsumx[i][j] == cumsumy[i][j] && cumsumx[i][j] > 0){
                    count++;
                }
            }
        }

        return count;
    }
};

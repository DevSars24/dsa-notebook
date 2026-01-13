/*
========================================================
Problem: Search a 2D Matrix
Link: https://leetcode.com/problems/search-a-2d-matrix/

Difficulty: Medium
Platform: LeetCode

--------------------------------------------------------
Problem Statement:
Given an m x n integer matrix with the following properties:
1. Integers in each row are sorted in ascending order.
2. Integers in each column are sorted in ascending order.

Given an integer target, return true if target is found
in the matrix, otherwise return false.

--------------------------------------------------------
Approach:
We use an efficient search strategy starting from the
top-right corner of the matrix.

Why top-right?
- Moving left decreases values.
- Moving down increases values.

At any cell (i, j):
- If matrix[i][j] > target → move left (j--)
- If matrix[i][j] < target → move down (i++)
- If equal → target found

This eliminates one row or one column at each step.

--------------------------------------------------------
Algorithm:
1. Initialize i = 0 (first row)
2. Initialize j = n - 1 (last column)
3. While i < m AND j >= 0:
   a. Compare matrix[i][j] with target
   b. Adjust i or j accordingly
4. If loop ends, target does not exist

--------------------------------------------------------
Time Complexity:
O(m + n)

Space Complexity:
O(1)

--------------------------------------------------------
Edge Cases Handled:
- Target at boundaries
- Target not present
- Single row / single column matrix
========================================================
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = n - 1;

        while (i < m && j >= 0) {
            if (matrix[i][j] > target) {
                j--;
            } 
            else if (matrix[i][j] < target) {
                i++;
            } 
            else {
                return true;
            }
        }
        return false;
    }
};

/*
    ============================================================
    LeetCode Problem: Set Matrix Zeroes
    Link: https://leetcode.com/problems/set-matrix-zeroes/

    Problem Statement:
    ------------------
    Given an m x n integer matrix, if an element is 0,
    set its entire row and column to 0.
    You must do it in place.

    Example:
    --------
    Input:
    1 1 1
    1 0 1
    1 1 1

    Output:
    1 0 1
    0 0 0
    1 0 1

    ------------------------------------------------------------
    Optimal Approach (O(1) Space):
    ------------------------------------------------------------
    Instead of using extra row[] and col[] arrays,
    we use first row and first column as markers.

    Steps:
    1. Check if first row contains zero.
    2. Check if first column contains zero.
    3. Use first row & column to mark zero positions.
    4. Update inner matrix based on markers.
    5. Finally update first row and column if needed.

    Time Complexity: O(m * n)
    Space Complexity: O(1)

    Author: Saurabh Singh Rajput
    ============================================================
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowImpacted = false;
        bool firstColImpacted = false;

        // Step 1: Check first row
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0){
                firstRowImpacted = true;
                break;
            }
        }

        // Step 2: Check first column
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                firstColImpacted = true;
                break;
            }
        }

        // Step 3: Use first row and column as markers
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 4: Update matrix based on markers
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: Update first row if needed
        if(firstRowImpacted){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }

        // Step 6: Update first column if needed
        if(firstColImpacted){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};


// ---------------------- Driver Code ----------------------

int main() {

    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    Solution obj;
    obj.setZeroes(matrix);

    cout << "\nMatrix after applying setZeroes:\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

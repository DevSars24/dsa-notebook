/***************************************************************
 *  Problem: Equal Sum Grid Partition I
 *  Platform: LeetCode
 *
 *  Approach:
 *  ----------
 *  We need to check if we can split the grid into two parts
 *  such that the sum of elements in both parts is equal.
 *
 *  Strategy:
 *  1. Compute total sum of grid.
 *  2. If total sum is odd → impossible → return false.
 *  3. Maintain row-wise cumulative sum.
 *  4. Traverse rows and check if at any point:
 *         upper_sum == total_sum - upper_sum
 *
 *  If yes → valid partition exists.
 *
 *  Time Complexity: O(m * n)
 *  Space Complexity: O(m + n)
 *
 ***************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int m = grid.size();       // number of rows
        int n = grid[0].size();    // number of columns

        // Row sum and column sum arrays
        vector<long long> rowSum(m, 0);
        vector<long long> colSum(n, 0);

        long long total = 0;

        /********************************************************
         * Step 1: Compute total sum + rowSum + colSum
         ********************************************************/
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                total += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }

        /********************************************************
         * Step 2: If total sum is odd → can't split equally
         ********************************************************/
        if(total % 2 != 0) {
            return false;
        }

        /********************************************************
         * Step 3: Try horizontal partition
         ********************************************************/
        long long upper = 0;

        for(int i = 0; i < m - 1; i++) {
            upper += rowSum[i];

            // Check if partition is valid
            if(upper == total - upper) {
                return true;
            }
        }

        /********************************************************
         * Step 4: Try vertical partition (extra improvement)
         * (optional but makes solution complete)
         ********************************************************/
        long long left = 0;

        for(int j = 0; j < n - 1; j++) {
            left += colSum[j];

            if(left == total - left) {
                return true;
            }
        }

        /********************************************************
         * No valid partition found
         ********************************************************/
        return false;
    }
};


/***************************************************************
 * Driver Code (Optional for Local Testing)
 ***************************************************************/
int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1, 2, 3},
        {3, 2, 1}
    };

    if(sol.canPartitionGrid(grid)) {
        cout << "Partition Possible ✅" << endl;
    } else {
        cout << "Partition Not Possible ❌" << endl;
    }

    return 0;
}

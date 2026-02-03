/**
 * ------------------------------------------------------------
 *  Problem: Number of Enclaves (LeetCode)
 * ------------------------------------------------------------
 *
 * An enclave is a land cell (1) that cannot reach the boundary
 * of the grid by moving up, down, left, or right.
 *
 * Approach:
 * ----------
 * 1. Run DFS from all boundary land cells and convert them to water.
 * 2. Remaining land cells are enclaves.
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * ----------------
 * O(m × n)
 *
 * Space Complexity:
 * -----------------
 * O(m × n) (DFS recursion stack)
 * ------------------------------------------------------------
 */

#include <vector>
using namespace std;

class Solution {
public:
    int m, n;

    // DFS to remove boundary-connected land
    void dfs(vector<vector<int>>& grid, int r, int c) {

        // Boundary or water check
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) {
            return;
        }

        // Mark land as water (visited)
        grid[r][c] = 0;

        // Explore all 4 directions
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int numEnclaves(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // First & last column
        for (int row = 0; row < m; row++) {
            if (grid[row][0] == 1)
                dfs(grid, row, 0);

            if (grid[row][n - 1] == 1)
                dfs(grid, row, n - 1);
        }

        // First & last row
        for (int col = 0; col < n; col++) {
            if (grid[0][col] == 1)
                dfs(grid, 0, col);

            if (grid[m - 1][col] == 1)
                dfs(grid, m - 1, col);
        }

        // Count remaining land
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};

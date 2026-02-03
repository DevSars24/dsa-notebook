/**
 * ------------------------------------------------------------
 *  Problem: Number of Closed Islands (LeetCode)
 * ------------------------------------------------------------
 *
 * A closed island is a group of 0s (land) completely surrounded
 * by 1s (water) on all four sides and NOT touching the boundary.
 *
 * Approach Used:
 * ----------------
 * Depth First Search (DFS)
 *
 * Core Idea:
 * ----------
 * - Traverse each land cell (0)
 * - Use DFS to explore the entire island
 * - If during DFS we go out of bounds → island is NOT closed
 * - If all directions remain valid → island IS closed
 *
 * DFS returns:
 *  - true  → island is closed
 *  - false → island touches boundary
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * ----------------
 * O(m × n)
 * Each cell is visited once.
 *
 * Space Complexity:
 * -----------------
 * O(m × n) (recursive DFS stack in worst case)
 * ------------------------------------------------------------
 */

#include <vector>
using namespace std;

class Solution {
public:
    int m, n;

    /**
     * DFS helper function
     * @param grid reference to grid
     * @param r current row
     * @param c current column
     * @return true if island part is closed, else false
     */
    bool dfs(vector<vector<int>>& grid, int r, int c) {

        // If out of grid bounds → island touches boundary
        if (r < 0 || c < 0 || r >= m || c >= n) {
            return false;
        }

        // If water or already visited → safe path
        if (grid[r][c] == 1) {
            return true;
        }

        // Mark current land as visited (convert to water)
        grid[r][c] = 1;

        // Explore all 4 directions
        bool left  = dfs(grid, r, c - 1);
        bool right = dfs(grid, r, c + 1);
        bool up    = dfs(grid, r - 1, c);
        bool down  = dfs(grid, r + 1, c);

        // Island is closed only if all directions are closed
        return left && right && up && down;
    }

    /**
     * Main function to count closed islands
     */
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        // Traverse entire grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Start DFS when land is found
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

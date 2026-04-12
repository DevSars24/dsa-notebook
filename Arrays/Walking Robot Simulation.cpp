/***************************************************************
 *  Problem: Walking Robot Simulation
 *  Platform: LeetCode
 *
 *  Description:
 *  -------------
 *  A robot starts at (0,0) facing North. It receives commands:
 *
 *   -2 → Turn left 90°
 *   -1 → Turn right 90°
 *   1-9 → Move forward 'x' steps
 *
 *  The robot must avoid obstacles. If next step hits an obstacle,
 *  it stops moving for that command.
 *
 *  Return the maximum Euclidean distance squared from origin.
 *
 *  ------------------------------------------------------------
 *  Optimized Approach:
 *  ------------------------------------------------------------
 *  Instead of using string hashing (slow), we use:
 *
 *      unordered_set<long long>
 *
 *  Encode coordinates using:
 *      key = (long long)x << 32 | y
 *
 *  This avoids string creation → faster lookup 🚀
 *
 *  ------------------------------------------------------------
 *  Direction Handling:
 *  ------------------------------------------------------------
 *  Directions stored as:
 *      North → (0,1)
 *      East  → (1,0)
 *      South → (0,-1)
 *      West  → (-1,0)
 *
 *  Use index rotation:
 *      Left  → (dir + 3) % 4
 *      Right → (dir + 1) % 4
 *
 *  ------------------------------------------------------------
 *  Time Complexity: O(N + M)
 *      N = commands, M = obstacles
 *
 *  Space Complexity: O(M)
 *
 ***************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Encode (x, y) into a single long long key
    long long encode(int x, int y) {
        return ((long long)x << 32) | (unsigned int)y;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        /********************************************************
         * Step 1: Store obstacles in hash set (fast lookup)
         ********************************************************/
        unordered_set<long long> obstacleSet;

        for (auto &obs : obstacles) {
            obstacleSet.insert(encode(obs[0], obs[1]));
        }

        /********************************************************
         * Step 2: Direction vectors
         * 0 = North, 1 = East, 2 = South, 3 = West
         ********************************************************/
        vector<pair<int,int>> dirs = {
            {0,1},   // North
            {1,0},   // East
            {0,-1},  // South
            {-1,0}   // West
        };

        int dir = 0; // initially facing North

        int x = 0, y = 0;
        int maxDist = 0;

        /********************************************************
         * Step 3: Process commands
         ********************************************************/
        for (int cmd : commands) {

            if (cmd == -2) {
                // Turn left
                dir = (dir + 3) % 4;

            } else if (cmd == -1) {
                // Turn right
                dir = (dir + 1) % 4;

            } else {
                // Move forward step-by-step
                for (int step = 0; step < cmd; step++) {

                    int nx = x + dirs[dir].first;
                    int ny = y + dirs[dir].second;

                    // If obstacle found → stop movement
                    if (obstacleSet.count(encode(nx, ny))) {
                        break;
                    }

                    x = nx;
                    y = ny;

                    // Update max distance
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};


/***************************************************************
 * Driver Code (Optional for Local Testing)
 ***************************************************************/
int main() {
    Solution sol;

    vector<int> commands = {4, -1, 3};
    vector<vector<int>> obstacles = {};

    cout << "Max Distance Squared: "
         << sol.robotSim(commands, obstacles) << endl;

    return 0;
}

/*
    ================================================================
    🧠 LeetCode Problem: Rotting Oranges
    🔗 Question Link:
    https://leetcode.com/problems/rotting-oranges/
    ================================================================

    📌 Problem Statement:

    You are given an m x n grid where:
        0 = empty cell
        1 = fresh orange
        2 = rotten orange

    Every minute, any fresh orange adjacent (up, down, left, right)
    to a rotten orange becomes rotten.

    Return the minimum number of minutes required so that
    no fresh orange remains.
    If impossible, return -1.

    ================================================================

    💡 Intuition:

    This is a classic MULTI-SOURCE BFS problem.

    Why BFS?
    Because rotting spreads level-by-level (minute by minute).
    Each level of BFS = 1 minute.

    Steps:
    1. Push all rotten oranges into queue (starting points).
    2. Count fresh oranges.
    3. Spread rot in 4 directions using BFS.
    4. Reduce fresh count whenever orange rots.
    5. If fresh becomes 0 → return minutes.
       Else → return -1.

    ================================================================

    ⚙️ Approach:

    1. Traverse grid:
        - Push all 2's into queue
        - Count total fresh oranges

    2. If freshcount == 0 → return 0

    3. Start BFS:
        - Process queue level by level
        - For each rotten orange:
            Check 4 directions
            If fresh found:
                Mark rotten
                Push into queue
                Decrease freshcount

    4. After BFS:
        - If freshcount == 0 → return minutes - 1
        - Else → return -1

    ================================================================

    ⏱ Time Complexity:
        O(m * n)

    📦 Space Complexity:
        O(m * n) (queue in worst case)

    ================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,int> p;

    // 4-direction movement (Up, Down, Left, Right)
    vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};

    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<p> que;
        int freshcount = 0;

        // Step 1: Initialize queue and count fresh oranges
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    que.push({i,j});
                }
                else if(grid[i][j] == 1){
                    freshcount++;
                }
            }
        }

        // If no fresh orange
        if(freshcount == 0)
            return 0;

        int minutes = 0;

        // Step 2: BFS
        while(!que.empty()) {

            int size = que.size();

            while(size--) {

                p curr = que.front();
                que.pop();

                int i = curr.first;
                int j = curr.second;

                for(vector<int>& dir : directions) {

                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i >= 0 && new_i < m &&
                       new_j >= 0 && new_j < n &&
                       grid[new_i][new_j] == 1) {

                        grid[new_i][new_j] = 2;
                        que.push({new_i, new_j});
                        freshcount--;
                    }
                }
            }

            minutes++;
        }

        return freshcount == 0 ? minutes - 1 : -1;
    }
};


/*
    ================================================================
    🧪 Dry Run Example:

    Input:
    [[2,1,1],
     [1,1,0],
     [0,1,1]]

    Minute 0:
    Rotten at (0,0)

    Minute 1:
    (0,1), (1,0) become rotten

    Minute 2:
    (0,2), (1,1) become rotten

    Minute 3:
    (2,1) becomes rotten

    Minute 4:
    (2,2) becomes rotten

    Total Minutes = 4

    ================================================================
*/

/*
===============================================================================
Problem Name   : Count Collisions on a Road
Platform       : LeetCode
Problem ID     : 2211
Difficulty     : Medium
Topic          : String | Two Pointers | Simulation

-------------------------------------------------------------------------------
Problem Link:
https://leetcode.com/problems/count-collisions-on-a-road/

-------------------------------------------------------------------------------
Problem Statement:
There are n cars on an infinitely long road.
Each car can move Left ('L'), Right ('R'), or Stay ('S').

Rules:
- R meets L  → 2 collisions
- Moving car meets S → 1 collision
- After collision, cars stop moving

Return the total number of collisions.

-------------------------------------------------------------------------------
Core Intuition:
--------------------------------
Some cars will NEVER collide:
- Leading 'L' cars (at the start) move left forever
- Trailing 'R' cars (at the end) move right forever

All other cars WILL eventually collide.

So instead of simulating collisions,
we simply IGNORE the safe cars and count the rest.

-------------------------------------------------------------------------------
Key Insight:
--------------------------------
1. Skip all 'L' from the left
2. Skip all 'R' from the right
3. In the remaining range:
   - Every non-'S' car causes exactly ONE collision

-------------------------------------------------------------------------------
Why This Works:
--------------------------------
Any 'R' inside will hit something ahead.
Any 'L' inside will hit something behind.
'S' cars don't initiate collisions.

No stack needed.
No simulation needed.
Just counting.

-------------------------------------------------------------------------------
Approach:
--------------------------------
- Use two pointers
- Shrink from both ends
- Count non-'S' characters in between

-------------------------------------------------------------------------------
Time Complexity:
--------------------------------
O(n)

Space Complexity:
--------------------------------
O(1)

-------------------------------------------------------------------------------
Key Takeaway:
--------------------------------
When behavior is deterministic,
count outcomes instead of simulating events.

===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {

        int n = directions.length();
        int i = 0, j = n - 1;

        // Skip safe cars
        while (i < n && directions[i] == 'L') i++;
        while (j >= 0 && directions[j] == 'R') j--;

        int collisions = 0;

        // Count collisions in remaining segment
        while (i <= j) {
            if (directions[i] != 'S') {
                collisions++;
            }
            i++;
        }

        return collisions;
    }
};

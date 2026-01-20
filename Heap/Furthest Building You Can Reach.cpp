/*
====================================================
LeetCode Problem: Furthest Building You Can Reach
Link:
https://leetcode.com/problems/furthest-building-you-can-reach/

----------------------------------------------------
INTUITION (Story Style):

You are moving across buildings from left to right.
Each building has a height.

➡ If the next building is shorter or same height:
   - No resource needed, just move.

➡ If the next building is taller:
   - You must either use BRICKS or a LADDER.

BRICKS:
- Limited resource
- Used equal to height difference

LADDERS:
- Can cover ANY height difference
- Very powerful, so should be used wisely

💡 Smart Strategy:
- Use BRICKS first for every upward jump
- Keep track of all jumps where bricks were used
- If bricks go negative:
    → Replace the LARGEST brick jump with a LADDER
    → Recover those bricks

If ladders also run out → stop.

----------------------------------------------------
KEY IDEA:

Always use ladders on the biggest jumps
and bricks on smaller jumps.

This greedy strategy is implemented using
a MAX HEAP (priority_queue).

----------------------------------------------------
APPROACH:

1. Traverse buildings from index 0 to n-2
2. Calculate height difference
3. If diff <= 0 → continue
4. Use bricks and push diff into max-heap
5. If bricks < 0:
    - Take back the largest brick usage
    - Use ladder instead
6. If ladders < 0 → return current index
7. If loop finishes → last building reached

----------------------------------------------------
TIME COMPLEXITY:
O(n log n)

SPACE COMPLEXITY:
O(n)

====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        // Max heap to store all positive height jumps
        priority_queue<int> pq;

        for (int i = 0; i < heights.size() - 1; i++) {

            int diff = heights[i + 1] - heights[i];

            // No resource needed if next building is not taller
            if (diff <= 0)
                continue;

            // Use bricks for now
            bricks -= diff;
            pq.push(diff);

            // If bricks go negative, convert the largest brick usage to ladder
            if (bricks < 0) {
                bricks += pq.top(); // recover bricks
                pq.pop();
                ladders--;

                // If no ladders left, cannot move further
                if (ladders < 0) {
                    return i;
                }
            }
        }

        // If all buildings are crossed
        return heights.size() - 1;
    }
};

/*
------------------------------------------------------------
Platform : LeetCode
Problem  : Minimum Number of Taps to Open to Water a Garden
Link     : https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
------------------------------------------------------------

Problem Summary:
You have a garden from point 0 to n.
Each tap at position i can water the range:
[i - ranges[i], i + ranges[i]]

You need to open minimum number of taps such that
the entire garden [0, n] is watered.
If impossible, return -1.

------------------------------------------------------------
Key Intuition (Greedy):
This problem reduces to:
👉 "Minimum intervals needed to cover [0, n]"

Steps:
1. Convert each tap into an interval [left, right].
2. For each left point, store the maximum right we can reach.
3. Use greedy like Jump Game:
   - maxEnd   → farthest point reachable so far
   - currEnd  → end of current tap coverage
   - when i > currEnd → need to open a new tap

------------------------------------------------------------
Why Greedy Works:
Always extend coverage as far as possible before opening
a new tap.

------------------------------------------------------------
Example:
n = 5
ranges = [3,4,1,1,0,0]

Intervals:
Tap 0 → [0,3]
Tap 1 → [0,5]

Only 1 tap is enough → Answer = 1

------------------------------------------------------------
Time Complexity  : O(n)
Space Complexity : O(n)
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

        // startEnd[i] = farthest right point we can reach starting from i
        vector<int> startEnd(n + 1, 0);

        // Build interval coverage
        for (int i = 0; i <= n; i++) {
            int left  = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);

            startEnd[left] = max(startEnd[left], right);
        }

        int taps = 0;
        int maxEnd = 0;
        int currEnd = 0;

        // Greedy traversal
        for (int i = 0; i <= n; i++) {

            // If we cannot reach this point
            if (i > maxEnd) {
                return -1;
            }

            // Need to open a new tap
            if (i > currEnd) {
                taps++;
                currEnd = maxEnd;
            }

            // Extend maximum reachable end
            maxEnd = max(maxEnd, startEnd[i]);
        }

        return taps;
    }
};

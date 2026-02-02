/*
------------------------------------------------------------
📌 Problem: Car Pooling
🔗 Link: https://leetcode.com/problems/car-pooling/

🧠 Approach: Difference Array + Prefix Sum (Sweep Line)
------------------------------------------------------------

We are given multiple trips where:
- trip[0] = number of passengers
- trip[1] = start location
- trip[2] = end location (exclusive)

Goal:
Check if we can complete all trips without exceeding
the given car capacity at any point.

------------------------------------------------------------
💡 Key Idea:
Use a map to track passenger changes at each location:
- At start location → passengers increase
- At end location → passengers decrease

Then process locations in sorted order and maintain
a running passenger count.
If at any point passengers > capacity → return false.

------------------------------------------------------------
⏱️ Time Complexity:
O(N log N) — due to ordered map traversal

🧮 Space Complexity:
O(N) — for storing events

------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Map to store passenger change events
        map<int, int> events;

        // Record pickup and drop events
        for (auto &trip : trips) {
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2];

            events[start] += passengers;  // pickup
            events[end]   -= passengers;  // drop
        }

        int currentPassengers = 0;

        // Process events in sorted order
        for (auto &it : events) {
            currentPassengers += it.second;

            // If capacity exceeded, return false
            if (currentPassengers > capacity)
                return false;
        }

        return true;
    }
};

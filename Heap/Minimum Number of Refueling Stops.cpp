/*
=====================================================
LeetCode Question:
Minimum Number of Refueling Stops

Link:
https://leetcode.com/problems/minimum-number-of-refueling-stops/

Approach:
Greedy + Max Heap (Priority Queue)

Idea:
- Fuel represents how far we can currently reach.
- Add fuel of all reachable stations into a max heap.
- When we can't move further, refuel from the station
  that provides the maximum fuel.
- Count the number of refuels.
=====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        // Max heap to store fuel from passed stations
        priority_queue<int> pq;

        int fuel = startFuel; // current reachable distance
        int stops = 0;        // number of refueling stops
        int i = 0;            // station index

        // While target is not reachable
        while (fuel < target) {

            // Add all reachable stations' fuel to heap
            while (i < stations.size() && stations[i][0] <= fuel) {
                pq.push(stations[i][1]);
                i++;
            }

            // No station to refuel from → impossible
            if (pq.empty())
                return -1;

            // Refuel from the station with maximum fuel
            fuel += pq.top();
            pq.pop();
            stops++;
        }

        return stops;
    }
};

/*
Example:
target = 100
startFuel = 10
stations = [[10,60],[20,30],[30,30],[60,40]]

Output:
2
*/

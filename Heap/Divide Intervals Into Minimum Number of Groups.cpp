/*
    LeetCode Problem:
    Divide Intervals Into Minimum Number of Groups
    https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

    Approach:
    - Sort intervals by start time
    - Use a min-heap (priority queue) to track the earliest ending group
    - If the current interval starts after the earliest ending interval,
      we can reuse that group
    - Otherwise, create a new group
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // Min-heap to store end times of active groups
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            // If we can reuse a group
            if (!pq.empty() && start > pq.top()) {
                pq.pop();
            }

            // Assign current interval to a group
            pq.push(end);
        }

        // Number of groups required
        return pq.size();
    }
};

/*
Example:
Input:  intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
Output: 3
*/

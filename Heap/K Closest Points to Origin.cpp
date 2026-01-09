/*
------------------------------------------------------------
Problem: K Closest Points to Origin
Link: https://leetcode.com/problems/k-closest-points-to-origin/

Approach:
- Use a MAX HEAP (priority_queue)
- Maintain heap size = k
- Push each point with its squared distance
- If heap size exceeds k, pop the farthest point

Why MAX heap?
- The farthest point stays on top
- Easy to remove when size > k

Time Complexity:
- O(n log k)

Space Complexity:
- O(k)

Author: Saurabh Singh Rajput
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // Max heap -> {distance, {x, y}}
        priority_queue<pair<int, pair<int,int>>> maxheap;

        vector<vector<int>> result;

        for (int i = 0; i < points.size(); i++) {

            int x = points[i][0];
            int y = points[i][1];

            // Squared distance (no need of sqrt)
            int dist = x*x + y*y;

            maxheap.push({dist, {x, y}});

            // Keep only k closest points
            if (maxheap.size() > k) {
                maxheap.pop();
            }
        }

        // Extract k closest points
        while (!maxheap.empty()) {
            auto top = maxheap.top();
            maxheap.pop();
            result.push_back({top.second.first, top.second.second});
        }

        return result;
    }
};

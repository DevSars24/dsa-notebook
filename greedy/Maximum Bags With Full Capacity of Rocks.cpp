/*
========================================================
LeetCode Problem: Maximum Bags With Full Capacity of Rocks
Platform       : LeetCode
Question Link  : https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/

--------------------------------------------------------
Problem Summary:
You are given two arrays:
1. capacity[i] -> maximum rocks bag i can hold
2. rocks[i]    -> rocks already present in bag i

You are also given:
additionalRocks -> extra rocks you can distribute

Goal:
Fill maximum number of bags completely using additional rocks.

--------------------------------------------------------
Approach:
1. For each bag, calculate how many rocks are still required:
      required[i] = capacity[i] - rocks[i]

2. Sort the required array (greedy strategy):
   - Fill bags that need the least rocks first

3. Traverse required array:
   - If required[i] == 0 → already full → count++
   - Else if additionalRocks >= required[i]
       - Use rocks
       - count++
   - Else break

--------------------------------------------------------
Time Complexity:
O(n log n)  (sorting)

Space Complexity:
O(n)
========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        int n = capacity.size();
        vector<int> required;

        // Step 1: Calculate required rocks for each bag
        for (int i = 0; i < n; i++) {
            required.push_back(capacity[i] - rocks[i]);
        }

        // Step 2: Sort required rocks
        sort(required.begin(), required.end());

        int count = 0;

        // Step 3: Greedily fill bags
        for (int i = 0; i < n; i++) {
            if (required[i] == 0) {
                count++; // already full
            } else if (additionalRocks >= required[i]) {
                additionalRocks -= required[i];
                count++;
            } else {
                break;
            }
        }

        return count;
    }
};

/*
=====================================================================
LeetCode Problem : 1833. Maximum Ice Cream Bars
Platform         : LeetCode
Problem Link     : https://leetcode.com/problems/maximum-ice-cream-bars/

---------------------------------------------------------------------
📌 Problem Statement:
You are given an integer array `costs`, where costs[i] is the price
of the ith ice cream bar.

You are also given an integer `coins` representing the total coins
available.

You can buy the ice cream bars in any order.
Return the maximum number of ice cream bars you can buy with the
given coins.

---------------------------------------------------------------------
🧠 Approach (Greedy + Sorting):
1. To maximize the number of ice creams, always buy the cheapest
   ice cream first.
2. Sort the `costs` array in ascending order.
3. Iterate through the sorted array:
   - If the current ice cream cost is greater than available coins,
     stop and return the count.
   - Otherwise, buy it and subtract the cost from coins.

---------------------------------------------------------------------
✏️ Example:
Input:
costs = [1,3,2,4,1], coins = 7

Sorted costs:
[1,1,2,3,4]

Buying process:
1 + 1 + 2 + 3 = 7 → 4 ice creams

Output:
4

---------------------------------------------------------------------
⏱️ Complexity Analysis:
Time Complexity  : O(n log n)
Space Complexity : O(1) (ignoring sort space)

=====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        // Sort ice cream costs
        sort(costs.begin(), costs.end());
        
        int ice_creams = 0;

        // Buy cheapest ice creams first
        for (int cost : costs) {
            if (cost > coins) {
                return ice_creams;
            }
            coins -= cost;
            ice_creams++;
        }

        return ice_creams;
    }
};

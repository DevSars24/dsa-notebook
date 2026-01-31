#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int x = numBottles;   // empty bottles tracker
        int y = numExchange;  // exchange rate
        int count = 0;        // extra bottles gained via exchange

        while (x >= y) {
            count += x / y;          // bottles obtained by exchange
            x = (x / y) + (x % y);   // new empty bottles
        }

        return numBottles + count;
    }
};

/*
LeetCode 1518 - Water Bottles
Approach:
- Drink all initial bottles
- Use empty bottles to exchange for new ones
- Repeat until exchange not possible

Time Complexity: O(log n)
Space Complexity: O(1)
*/

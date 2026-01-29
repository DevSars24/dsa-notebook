/*
===============================================================================
File Name   : HandOfStraights.cpp
Problem    : 846. Hand of Straights (LeetCode)
Link       : https://leetcode.com/problems/hand-of-straights/
Difficulty : Medium
Language   : C++

===============================================================================
PROBLEM STATEMENT
-------------------------------------------------------------------------------
Alice has some number of cards and she wants to rearrange the cards into groups
such that:
1. Each group has exactly `groupSize` cards.
2. Cards in each group are consecutive numbers.

Given an integer array `hand` and an integer `groupSize`,
return true if the cards can be rearranged into such groups,
otherwise return false.

===============================================================================
APPROACH (Greedy + Ordered Map)
-------------------------------------------------------------------------------
1. If total number of cards is not divisible by `groupSize`,
   it is impossible to form valid groups → return false.

2. Use a map<int, int> to store frequency of each card.
   - `map` keeps keys sorted automatically.

3. While the map is not empty:
   - Take the smallest available card (map.begin()->first).
   - Try to form a group of size `groupSize` starting from it.
   - For every consecutive number:
       a) If it does not exist → return false.
       b) Decrease its frequency.
       c) Remove it from map if frequency becomes zero.

4. If all cards are successfully grouped, return true.

===============================================================================
WHY GREEDY WORKS?
-------------------------------------------------------------------------------
The smallest available card cannot be placed anywhere else except
at the start of a consecutive group. Starting from it avoids gaps
and guarantees correctness.

===============================================================================
TIME & SPACE COMPLEXITY
-------------------------------------------------------------------------------
Time Complexity  : O(N log N)
- N insertions in map → O(N log N)
- Each card processed once.

Space Complexity : O(N)
- Frequency map storage.

===============================================================================
CODE IMPLEMENTATION
-------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        // Total cards must be divisible by groupSize
        if(n % groupSize != 0) return false;

        // Frequency map (sorted)
        map<int,int> mp;

        // Count frequency of each card
        for(int card : hand){
            mp[card]++;
        }

        // Try to form groups greedily
        while(!mp.empty()){

            // Smallest available card
            int start = mp.begin()->first;

            // Check for consecutive cards
            for(int i = start; i < start + groupSize; i++){

                // Missing card
                if(mp.count(i) == 0){
                    return false;
                }

                // Use the card
                mp[i]--;

                // Remove if frequency becomes zero
                if(mp[i] == 0){
                    mp.erase(i);
                }
            }
        }

        return true;
    }
};

/*
===============================================================================
EXAMPLE
-------------------------------------------------------------------------------
Input  : hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output : true

Groups formed:
[1,2,3], [2,3,4], [6,7,8]

===============================================================================
AUTHOR
-------------------------------------------------------------------------------
Saurabh Singh Rajput

===============================================================================
*/

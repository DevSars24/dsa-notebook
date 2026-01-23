/*
------------------------------------------------------------
LeetCode Problem: Boats to Save People
Link: https://leetcode.com/problems/boats-to-save-people/

Problem Statement:
You are given an array `people` where people[i] is the weight of the ith person,
and an integer `limit` which is the maximum weight a boat can carry.

Each boat can carry at most 2 people at the same time, provided the sum of their
weights is less than or equal to `limit`.

Return the minimum number of boats needed to carry every given person.

------------------------------------------------------------
Approach (Greedy + Two Pointers):

1. Sort the array of people by weight.
2. Use two pointers:
   - i -> lightest person
   - j -> heaviest person
3. Always try to pair the lightest person with the heaviest person.
   - If their combined weight <= limit, put both in one boat.
   - Otherwise, the heaviest person goes alone.
4. Each iteration uses exactly one boat.
5. Continue until all people are assigned boats.

------------------------------------------------------------
Time Complexity: O(n log n)  [due to sorting]
Space Complexity: O(1)       [in-place sort, ignoring input array]
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        // Step 1: Sort people by weight
        sort(people.begin(), people.end());

        int i = 0;                      // lightest person
        int j = people.size() - 1;      // heaviest person
        int boats = 0;

        // Step 2: Two pointer greedy pairing
        while (i <= j) {

            // If lightest + heaviest can go together
            if (people[i] + people[j] <= limit) {
                i++;
                j--;
            } 
            // Otherwise, heaviest goes alone
            else {
                j--;
            }

            // One boat used in each iteration
            boats++;
        }

        return boats;
    }
};

/*
====================================================
LeetCode: Maximum Population Year
Problem Link:
https://leetcode.com/problems/maximum-population-year/

Author: Saurabh Singh
Language: C++
Approach: Sweep Line Algorithm
====================================================

PROBLEM STATEMENT:
You are given a list of population logs.
Each log contains:
logs[i] = [birthYear, deathYear]

A person is alive from birthYear to deathYear - 1.

Return the earliest year with the maximum population.

----------------------------------------------------

APPROACH (SWEEP LINE):
1. For every person:
   - Add +1 at birth year
   - Add -1 at death year
2. Store all events as (year, change)
3. Sort events by year
4. Traverse events while keeping track of:
   - Current population
   - Maximum population
5. The first year where population is maximum is the answer

----------------------------------------------------

TIME COMPLEXITY:
O(N log N)  → due to sorting

SPACE COMPLEXITY:
O(N) → event list

----------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        // Stores (year, population change)
        vector<pair<int, int>> events;

        // Step 1: Create events
        for (auto &log : logs) {
            events.push_back({log[0], +1}); // birth
            events.push_back({log[1], -1}); // death
        }

        // Step 2: Sort events by year
        sort(events.begin(), events.end());

        int currentPopulation = 0;
        int maxPopulation = 0;
        int answerYear = 0;

        // Step 3: Sweep through timeline
        for (auto &event : events) {
            currentPopulation += event.second;

            // Update max population and year
            if (currentPopulation > maxPopulation) {
                maxPopulation = currentPopulation;
                answerYear = event.first;
            }
        }

        return answerYear;
    }
};

/*
----------------------------------------------------
EXAMPLE:
Input:
logs = [[1993,1999],[2000,2010]]

Events:
1993 +1
1999 -1
2000 +1
2010 -1

Output:
1993
----------------------------------------------------

RESULT:
✔ Runtime: 0 ms (Beats 100%)
✔ Memory: 11.14 MB
----------------------------------------------------
*/

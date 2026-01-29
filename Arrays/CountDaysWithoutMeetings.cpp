/*
===============================================================================
File Name   : CountDaysWithoutMeetings.cpp
Problem    : Count Days Without Meetings
Platform   : LeetCode
Link       : https://leetcode.com/problems/count-days-without-meetings/
Difficulty : Medium
Language   : C++

===============================================================================
PROBLEM STATEMENT
-------------------------------------------------------------------------------
You are given:
- An integer `days` representing total days.
- A 2D array `meetings`, where each meeting is given as [startDay, endDay].

Meetings may overlap.
Return the number of days with NO meetings scheduled.

===============================================================================
APPROACH (Greedy + Interval Merging)
-------------------------------------------------------------------------------
1. Sort all meetings by start day.
2. Track the end of the last merged meeting interval.
3. For every meeting:
   - If the current meeting starts after the last end,
     count the gap as free days.
   - Extend the end boundary using max().
4. After processing all meetings, count remaining days till `days`.

===============================================================================
WHY THIS WORKS?
-------------------------------------------------------------------------------
Sorting ensures meetings are processed in order.
Merging overlapping intervals avoids double counting.
Gaps between merged intervals represent free days.

===============================================================================
TIME & SPACE COMPLEXITY
-------------------------------------------------------------------------------
Time Complexity  : O(N log N)  (sorting)
Space Complexity : O(1) extra space

===============================================================================
CODE
-------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        // Sort meetings by start day
        sort(meetings.begin(), meetings.end());

        int result = 0;
        int end = 0;

        for (auto &meet : meetings) {
            // Gap found
            if (meet[0] > end) {
                result += meet[0] - end - 1;
            }
            // Extend merged interval
            end = max(end, meet[1]);
        }

        // Days after last meeting
        if (days > end) {
            result += days - end;
        }

        return result;
    }
};

/*
===============================================================================
EXAMPLE
-------------------------------------------------------------------------------
Input:
days = 10
meetings = [[1,2],[4,5],[7,8]]

Output:
4

Free days = {3,6,9,10}

===============================================================================
AUTHOR
-------------------------------------------------------------------------------
Saurabh Singh Rajput
===============================================================================
*/

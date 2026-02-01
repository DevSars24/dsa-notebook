/*
    File Name   : minimum_meeting_rooms.cpp
    Author      : Saurabh Singh
    Platform    : GeeksforGeeks
    Problem     : Minimum Meeting Rooms
    Approach    : Sweep Line Algorithm using Map
    Language    : C++
    
    --------------------------------------------------
    PROBLEM STATEMENT:
    Given two integer arrays start[] and end[] representing
    the start and end times of meetings, find the minimum
    number of conference rooms required.

    --------------------------------------------------
    INTUITION:
    Each meeting increases room requirement at its start
    time and decreases it at its end time.

    If we:
    + add +1 at start time
    + add -1 at end time

    Then sweeping the timeline and tracking the maximum
    overlap gives the minimum rooms required.

    --------------------------------------------------
    TIME COMPLEXITY:
    O(N log N)  -> due to ordered map

    SPACE COMPLEXITY:
    O(N)

    --------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        map<int, int> events;

        int n = start.size();

        // Mark start and end events
        for (int i = 0; i < n; i++) {
            events[start[i]]++;   // meeting starts
            events[end[i]]--;     // meeting ends
        }

        int overlaps = 0;
        int maxOverlap = 0;

        // Sweep through timeline
        for (auto it : events) {
            overlaps += it.second;
            maxOverlap = max(maxOverlap, overlaps);
        }

        return maxOverlap;
    }
};

/*
    --------------------------------------------------
    SAMPLE INPUT:
    start = [1, 3, 5]
    end   = [2, 6, 10]

    OUTPUT:
    2

    --------------------------------------------------
    EXPLANATION:
    Maximum 2 meetings overlap at a time,
    hence 2 rooms are required.
    --------------------------------------------------
*/

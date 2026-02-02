/**
 * ------------------------------------------------------------
 * File: MyCalendarThree.cpp
 * Problem: LeetCode 732 - My Calendar III
 * Difficulty (as per LeetCode): Hard 😅
 * Actual Difficulty: Medium (Logic-based)
 * ------------------------------------------------------------
 *
 * 🧠 Core Idea:
 * This solution uses the **Line Sweep / Difference Array** technique.
 *
 * We do NOT track individual intervals.
 * Instead, we track:
 *   - +1 at startTime (event starts)
 *   - -1 at endTime   (event ends)
 *
 * By iterating over time in sorted order and maintaining
 * a running sum, we find the maximum number of overlapping
 * events at any point in time.
 *
 * ------------------------------------------------------------
 * Data Structure Used:
 *   map<int, int> events
 *
 * Why map?
 * - Automatically keeps keys sorted (timeline order)
 * - Efficient insertion and traversal
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *   book() → O(N log N)
 *   (log N for map insertions, N for traversal)
 *
 * Space Complexity:
 *   O(N) where N = number of bookings
 *
 * ------------------------------------------------------------
 */

#include <map>
#include <algorithm>
using namespace std;

class MyCalendarThree {
public:
    // Stores timeline changes
    map<int, int> events;

    MyCalendarThree() {}

    int book(int startTime, int endTime) {
        // Mark the start and end of an event
        events[startTime] += 1;
        events[endTime]   -= 1;

        int activeEvents = 0;
        int maxOverlap   = 0;

        // Line sweep through timeline
        for (auto &it : events) {
            activeEvents += it.second;
            maxOverlap = max(maxOverlap, activeEvents);
        }

        return maxOverlap;
    }
};

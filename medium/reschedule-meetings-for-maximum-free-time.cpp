// LeetCode Problem: 3439. Reschedule Meetings for Maximum Free Time I
// Link: [https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/](https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/)
// Difficulty: Medium

/*
============================ PROBLEM DESCRIPTION ============================
You are given:

* An integer eventTime representing an event running from time 0 to eventTime.
* Two arrays startTime[] and endTime[] of size n, representing n non-overlapping
  meetings where the i-th meeting occurs in [startTime[i], endTime[i]].

You are allowed to reschedule at most k meetings by shifting their start times
(keeping their durations the same), such that:

* The relative order of meetings remains the same
* Meetings do not overlap
* Meetings stay within [0, eventTime]

Goal:
Return the maximum continuous free time that can be obtained.

============================ CORE OBSERVATION ============================
If we look at the event timeline, the free time exists:

1. Before the first meeting
2. Between consecutive meetings
3. After the last meeting

If we remove (reschedule) k meetings, we effectively merge (k + 1) consecutive
free gaps into one large continuous free interval.

Thus, the problem reduces to:
➡ Find the maximum sum of (k + 1) consecutive free-time gaps.

This is a classic FIXED-SIZE SLIDING WINDOW problem.

============================ APPROACH ============================
Step 1: Construct an array `freeTime[]` containing all free gaps
- freeTime[0] = startTime[0]
- freeTime[i] = startTime[i] - endTime[i-1]  (gap between meetings)
- freeTime[last] = eventTime - endTime[last]

Step 2: Use a sliding window of size (k + 1)
- Compute the sum of the first (k + 1) gaps
- Slide the window and keep updating the maximum sum

============================ TIME & SPACE COMPLEXITY ============================
Time Complexity: O(n)
Space Complexity: O(n)

============================ IMPLEMENTATION ============================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int maxFreeTime(int eventTime, int k,
vector<int>& startTime,
vector<int>& endTime) {

```
    vector<int> freeTime;

    // Free time before the first meeting
    freeTime.push_back(startTime[0]);

    // Free time between meetings
    for (int i = 1; i < startTime.size(); i++) {
        freeTime.push_back(startTime[i] - endTime[i - 1]);
    }

    // Free time after the last meeting
    freeTime.push_back(eventTime - endTime.back());

    // Sliding window of size (k + 1)
    int n = freeTime.size();
    int window = k + 1;

    int currsum = 0;
    for (int i = 0; i < window; i++) {
        currsum += freeTime[i];
    }

    int maxsum = currsum;

    for (int i = 1; i <= n - window; i++) {
        currsum = currsum - freeTime[i - 1] + freeTime[i + window - 1];
        maxsum = max(maxsum, currsum);
    }

    return maxsum;
}
```

};

/*
============================ KEY TAKEAWAYS ============================
✔ Convert meeting schedule into free-time gaps
✔ Removing k meetings merges (k + 1) gaps
✔ Fixed-size sliding window gives optimal solution
✔ Clean O(n) solution suitable for interviews
*/

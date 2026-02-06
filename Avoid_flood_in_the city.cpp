/*
    File: avoid_flood_in_the_city.cpp
    Problem: Avoid Flood in The City (LeetCode)

    Intuition:
    -----------
    - If rains[i] > 0 → lake rains[i] gets filled on day i.
    - If the same lake rains again before being dried → flood.
    - rains[i] == 0 → we can choose ONE lake to dry on that day.

    Goal:
    -----
    Dry the correct lake on the correct zero-day so that
    no lake floods. If impossible, return empty array.

    Key Observations:
    -----------------
    1. When a lake rains again, it MUST be dried sometime
       after its previous rain and before today.
    2. To ensure this, we should always dry it at the earliest
       available zero day after its last rain.

    Data Structures Used:
    ---------------------
    unordered_map<int, int> lastRain
        - Stores the last day a lake was filled.

    set<int> zeroDays
        - Stores indices of days where rains[i] == 0.
        - Ordered set allows us to find the earliest valid day
          using lower_bound.

    Algorithm:
    ----------
    1. Iterate day by day.
    2. If rains[i] == 0:
        - Add day i to zeroDays.
    3. If rains[i] > 0:
        - If lake was seen before:
            - Find a zero day strictly AFTER lastRain[lake]
              using lower_bound.
            - If none exists → flood → return {}.
            - Dry this lake on that zero day.
        - Update lastRain[lake] = i.
    4. Remaining zero days can dry any lake (assign 1).

    Time Complexity:
    ----------------
    O(n log n)

    Space Complexity:
    -----------------
    O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);      // default dry any lake
        unordered_map<int, int> lastRain;
        set<int> zeroDays;

        for (int i = 0; i < n; i++) {
            int lake = rains[i];

            if (lake == 0) {
                zeroDays.insert(i);
            } else {
                ans[i] = -1;  // raining day

                // lake already full earlier
                if (lastRain.count(lake)) {
                    // find first zero day AFTER last rain
                    auto it = zeroDays.lower_bound(lastRain[lake]);

                    if (it == zeroDays.end()) {
                        return {}; // flood unavoidable
                    }

                    ans[*it] = lake;   // dry this lake
                    zeroDays.erase(it);
                }

                lastRain[lake] = i;
            }
        }

        return ans;
    }
};

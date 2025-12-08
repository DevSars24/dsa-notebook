/*
    LEETCODE 845 — LONGEST MOUNTAIN IN ARRAY
    ----------------------------------------

    A mountain is defined as:
        - Strictly increasing sequence
        - Followed by strictly decreasing sequence
        - Length must be at least 3
        - arr[left] < ... < arr[peak] > ... > arr[right]

    Our goal:
        Find the LENGTH of the longest subarray which forms a valid mountain.

    -------------------------------------------------------------------------
    ⭐ INTUITION & TWO-POINTER TEMPLATE
    -------------------------------------------------------------------------

    1) A valid mountain MUST have a peak at index i:
           arr[i] > arr[i - 1] AND arr[i] > arr[i + 1]

       So our first job = IDENTIFY ALL PEAKS.

    2) Once we detect a peak:
           Expand LEFT pointer while values strictly increase towards the peak.
           Expand RIGHT pointer while values strictly decrease away from the peak.

       Example expansion:
            left <-- peak --> right

            while(left > 0 && arr[left-1] < arr[left]) left--;
            while(right < n-1 && arr[right] > arr[right+1]) right++;

    3) Length of current mountain:
            mountain_length = right - left + 1

    4) Keep updating global maximum:
            ans = max(ans, mountain_length)

    -------------------------------------------------------------------------
    ⭐ TIME COMPLEXITY
    -------------------------------------------------------------------------
    O(n)
      - Because even though we have nested loops, each pointer moves
        across the array AT MOST ONCE in its lifetime.

    -------------------------------------------------------------------------
    ⭐ EDGE CASES
    -------------------------------------------------------------------------
    - If array size < 3 → impossible to form a mountain
    - Multiple disjoint mountains → choose the longest
    - Flat sections (equal values) break mountain definition

    -------------------------------------------------------------------------
    ⭐ TEMPLATE YOU CAN REUSE FOR MANY PROBLEMS:
    -------------------------------------------------------------------------
        for (i = 1 → n-2):
            if peak:
                expand left
                expand right
                update answer
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {

        int n = arr.size();
        if (n < 3) return 0;   // A mountain must be at least length 3

        int ans = 0;

        // Loop from 1 to n-2 because peak cannot be at ends
        for (int i = 1; i < n - 1; i++) {

            // ----------------------------------------------------------
            // ⭐ STEP 1 → Identify a valid peak
            // ----------------------------------------------------------
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {

                int left = i;
                int right = i;

                // ----------------------------------------------------------
                // ⭐ STEP 2 → Expand left while strictly increasing
                // ----------------------------------------------------------
                while (left > 0 && arr[left - 1] < arr[left])
                    left--;

                // ----------------------------------------------------------
                // ⭐ STEP 3 → Expand right while strictly decreasing
                // ----------------------------------------------------------
                while (right < n - 1 && arr[right] > arr[right + 1])
                    right++;

                // ----------------------------------------------------------
                // ⭐ STEP 4 → Calculate mountain length
                // ----------------------------------------------------------
                int mountainLength = right - left + 1;

                // ----------------------------------------------------------
                // ⭐ STEP 5 → Update global maximum
                // ----------------------------------------------------------
                ans = max(ans, mountainLength);
            }
        }

        return ans;
    }
};

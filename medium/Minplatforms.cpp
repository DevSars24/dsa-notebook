/*
===========================================================
🚉 Minimum Platforms
Problem Link:
https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
===========================================================

❓ Problem Statement
-------------------
Given two arrays:

arr[]  -> arrival times of trains
dep[]  -> departure times of trains

Times are in 24-hour HHMM format.

Find the minimum number of platforms required so that
no train has to wait.

Rules:
- A platform cannot be shared by two trains at the same time.
- If a train arrives before another departs, an extra platform is needed.

-----------------------------------------------------------

🧠 Intuition (Hinglish / WhatsApp style)
---------------------------------------
Bhai simple soch 👇

Har train ka ek time interval hota hai:
[arrival , departure]

Jab 2 ya zyada trains ek hi time pe station pe khadi hoti hain
➜ utni platforms chahiye

👉 Question actually yeh pooch raha hai:
"Maximum ek time pe kitni trains station par present thi?"

Aur wahi answer hota hai:
Minimum Platforms 💯

-----------------------------------------------------------

🔑 Core Idea (Hidden Trick)
--------------------------
- Arrival ko event maan lo  -> +1
- Departure ko event maan lo -> -1
- Timeline pe left se right sweep karo
- Maximum overlap = answer

-----------------------------------------------------------

🧩 Algorithm (Step by Step)
--------------------------
1) Arrival aur Departure arrays ko sort karo
2) Do pointers lo:
   - i -> arrival pointer
   - j -> departure pointer

3) Variables:
   - platforms     -> abhi kitni trains station pe hain
   - maxPlatforms  -> maximum platforms required

4) Sweep the timeline:
   - Agar arr[i] <= dep[j]
       * nayi train aa gayi
       * purani train abhi gayi nahi
       * platforms++
   - Else
       * ek train chali gayi
       * platforms--

5) Har step pe maxPlatforms update karo

-----------------------------------------------------------

💡 Important Observation
------------------------
Condition:
if (arr[i] <= dep[j])

Matlab:
"Arrival ho gayi
but departure abhi tak hui nahi
isliye overlap ho raha hai"

Isliye conflict = extra platform

-----------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {

        int n = arr.size();

        // Step 1: Sort arrival & departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0;              // arrival pointer
        int j = 0;              // departure pointer
        int platforms = 0;      // current platforms in use
        int maxPlatforms = 0;   // answer

        // Step 2: Sweep the timeline
        while (i < n && j < n) {

            // New train arrives before previous one departs
            if (arr[i] <= dep[j]) {
                platforms++;
                maxPlatforms = max(maxPlatforms, platforms);
                i++;
            }
            // Train departs
            else {
                platforms--;
                j++;
            }
        }

        return maxPlatforms;
    }
};

/*
⏱️ Time & Space Complexity
--------------------------
Time Complexity  : O(n log n)  (sorting)
Space Complexity : O(1)

-----------------------------------------------------------

🧠 One-line Interview Explanation
---------------------------------
"We sort arrival and departure times and simulate the station
timeline. Whenever an arrival happens before a departure,
platforms increase. The maximum platforms used at any moment
is the answer."

-----------------------------------------------------------

*/

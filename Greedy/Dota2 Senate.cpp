/*
=====================================================================
LeetCode Problem : 649. Dota2 Senate
Platform         : LeetCode
Problem Link     : https://leetcode.com/problems/dota2-senate/

---------------------------------------------------------------------
📌 Problem Statement:
In the Dota2 senate, each senator belongs to one of two parties:
- 'R' → Radiant
- 'D' → Dire

Each round:
- A senator can ban one senator of the opposite party.
- Banned senators are removed from the senate.
- Remaining senators move to the next round in the same order.

The process continues until only one party remains.

Return:
- "Radiant" if Radiant wins
- "Dire" if Dire wins

---------------------------------------------------------------------
🧠 Approach (Simulation using String Erase):
1. Count total Radiant (R) and Dire (D) senators.
2. Traverse the senate circularly using an index.
3. When a senator is encountered:
   - Remove the next available senator of the opposite party
     (circular search).
4. Update counts and adjust index after erase.
5. Stop when one party count becomes zero.

⚠️ Note:
This approach directly simulates the banning process using
string modification. While logically intuitive, it has higher
time complexity compared to the queue-based solution.

---------------------------------------------------------------------
⏱️ Complexity Analysis:
Time Complexity  : O(n²) in worst case (due to string erase)
Space Complexity : O(1) extra space

=====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {

        int R = count(senate.begin(), senate.end(), 'R');
        int D = senate.size() - R;

        int idx = 0;

        while (R > 0 && D > 0) {

            int n = senate.size();

            if (senate[idx] == 'R') {
                int j = (idx + 1) % n;
                while (senate[j] != 'D')
                    j = (j + 1) % n;

                senate.erase(senate.begin() + j);
                D--;

                if (j < idx) idx--;
            } 
            else { // senate[idx] == 'D'
                int j = (idx + 1) % n;
                while (senate[j] != 'R')
                    j = (j + 1) % n;

                senate.erase(senate.begin() + j);
                R--;

                if (j < idx) idx--;
            }

            idx = (idx + 1) % senate.size();
        }

        return (R == 0) ? "Dire" : "Radiant";
    }
};

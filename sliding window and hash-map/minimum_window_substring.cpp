/*
=========================================================
File Name : minimum_window_substring.cpp
Problem   : Minimum Window Substring (LeetCode 76)
Difficulty: Hard
=========================================================

PROBLEM:
Given two strings s and t, find the minimum window in s
which contains all characters of t (including duplicates).
If no such window exists, return "".

---------------------------------------------------------
APPROACH:
Sliding Window + HashMap

Key Ideas:
- Use a frequency map for string t
- Expand window using right pointer (j)
- Decrease required character count
- When all characters are matched, shrink window from left
- Track minimum length window

---------------------------------------------------------
TIME COMPLEXITY : O(n)
SPACE COMPLEXITY: O(1)  (at most 52 characters)
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> mp;

        // Frequency map of t
        for (char ch : t) {
            mp[ch]++;
        }

        int i = 0, j = 0;
        int count = t.size();    // total characters needed
        int minLen = INT_MAX;
        int start = 0;

        while (j < s.size()) {

            // Acquire character
            if (mp[s[j]] > 0) {
                count--;
            }
            mp[s[j]]--;

            // Try shrinking the window
            while (count == 0) {

                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    count++;
                }
                i++;
            }

            j++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};

/*
Example:
Input : s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
*/

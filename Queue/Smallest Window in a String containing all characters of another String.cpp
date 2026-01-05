/*
------------------------------------------------------------
Problem: Smallest Window in a String containing all characters of another String
Platform: GeeksforGeeks
Link:
https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

------------------------------------------------------------
Problem Statement:
Given two strings:
- s (the main string)
- p (the pattern string)

Find the smallest window (substring) in s that contains
all characters of p (including frequency).

If no such window exists, return "-1".

------------------------------------------------------------
Core Intuition (IMPORTANT):

This problem is NOT about comparing two maps.
It is about tracking the SHORTAGE of required characters.

Key idea:
- Maintain a frequency map of pattern characters
- Maintain a variable `count` that tells:
  how many characters are still required to make a valid window

------------------------------------------------------------
Why this approach works:

1. `count` starts with p.size()
   → means all characters are initially missing

2. While expanding window (j pointer):
   - If current character is still needed (mp[ch] > 0)
     → decrease count
   - Decrease mp[ch] in all cases

3. When `count == 0`:
   → window is VALID
   → try shrinking it from left to make it minimum

4. While shrinking (i pointer):
   - Restore character frequency
   - If any required character becomes missing again
     (mp[ch] > 0)
     → increase count
     → window becomes invalid, stop shrinking

------------------------------------------------------------
Time Complexity: O(N)
Space Complexity: O(1) (since alphabet size is bounded)

------------------------------------------------------------
*/

class Solution {
public:
    string smallestWindow(string &s, string &p) {

        unordered_map<char,int> mp;

        // Frequency map of pattern
        for(char ch : p)
            mp[ch]++;

        int i = 0, j = 0;
        int count = p.size();   // number of required characters
        int minLen = INT_MAX;
        int start = 0;

        while(j < s.size()) {

            // If character is still required
            if(mp[s[j]] > 0)
                count--;

            mp[s[j]]--;

            // Window is valid
            while(count == 0) {

                if(j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                // Shrink from left
                mp[s[i]]++;
                if(mp[s[i]] > 0)
                    count++;

                i++;
            }

            j++;
        }

        if(minLen == INT_MAX)
            return "-1";

        return s.substr(start, minLen);
    }
};

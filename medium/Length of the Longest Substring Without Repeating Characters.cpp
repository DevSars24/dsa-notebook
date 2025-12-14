/************************************************************
 *  Problem Name:
 *  Length of the Longest Substring Without Repeating Characters
 *
 *  Platform:
 *  GeeksforGeeks
 *  https://www.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1
 *
 *  ---------------------------------------------------------
 *  Problem Statement:
 *  Given a string s, find the length of the longest substring
 *  without repeating characters.
 *
 *  ---------------------------------------------------------
 *  Example:
 *  Input:  "abcabcbb"
 *  Output: 3
 *  Explanation: "abc" is the longest substring with all
 *               unique characters.
 *
 *  ---------------------------------------------------------
 *  Approach Used:
 *  Sliding Window (Two Pointers)
 *
 *  ---------------------------------------------------------
 *  Key Idea:
 *  - Use two pointers i (start) and j (end) to maintain a window.
 *  - Use an unordered_set to store unique characters in the window.
 *  - Expand the window using j.
 *  - If a duplicate character is found, shrink the window from
 *    the left (i) until the duplicate is removed.
 *  - Track the maximum window size.
 *
 *  ---------------------------------------------------------
 *  Algorithm Steps:
 *  1. Initialize i = 0, j = 0
 *  2. Create an unordered_set<char> to store characters
 *  3. While j < n:
 *      - If s[j] already exists in the set:
 *          - Remove s[i] from set
 *          - Increment i
 *      - Insert s[j] into set
 *      - Update max length
 *      - Increment j
 *
 *  ---------------------------------------------------------
 *  Time Complexity:
 *  O(N)
 *  Each character is added and removed from the set at most once.
 *
 *  ---------------------------------------------------------
 *  Space Complexity:
 *  O(N)
 *  For storing characters in the unordered_set.
 *
 ************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestUniqueSubstring(string &s) {

        int n = s.size();
        int i = 0, j = 0;
        unordered_set<char> st;

        int count = 0;
        int maxlength = 0;

        while (j < n) {

            // Shrink window if duplicate found
            while (st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                count--;
                i++;
            }

            // Expand window
            st.insert(s[j]);
            count++;

            // Update maximum length
            maxlength = max(maxlength, count);
            j++;
        }

        return maxlength;
    }
};

/*
---------------------------------------------------------
 Dry Run Example:
 s = "abba"

 i=0, j=0 -> window = "a"
 i=0, j=1 -> window = "ab"
 duplicate 'b' found
 shrink -> remove 'a'
 shrink -> remove 'b'
 window = "b"
 continue...

 Final Answer = 2
---------------------------------------------------------
*/

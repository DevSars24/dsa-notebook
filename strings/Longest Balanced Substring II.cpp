/*
    =============================================================
    LeetCode Problem: Longest Balanced Substring II
    Link: https://leetcode.com/problems/longest-balanced-substring-ii/

     Problem Summary:
    -------------------
    You are given a string s containing only the characters
    'a', 'b', and 'c'.

    A substring is called balanced if:
    - It contains only one or two or all three characters.
    - The frequencies of those characters within the substring
      match a pattern that satisfies the definition of balanced.

    The task is to return the length of the longest balanced
    substring that can be found in s.

    Examples:
    -------------
    Example 1:
    Input:  "abcabcbbabb"
    Output:    6
    Explanation:
      Substring "abcabc" is balanced.

    Example 2:
    Input:  "aaaaaa"
    Output:     6
    Explanation:
      The entire string is balanced because all
      characters are the same.

    =============================================================

     Intuition & Approach:
    ------------------------
    This problem has 3 main scenarios:

     Case 1: All Same Character
    --------------------------------
    If the substring contains only one character type like
    "aaaaaaa" → longest balanced substring = longest run
    of identical letters.

     Case 2: Exactly Two Characters
    ----------------------------------
    For each pair (a,b), (a,c), (b,c), the balanced substring
    requires count of both to be equal.

    How to find efficiently?
      ➤ Use prefix difference
      ➤ If diff repeats at indices i and j,
        then substring (i+1 … j) has equal counts

     Case 3: Exactly Three Characters
    ------------------------------------
    Balanced substring needs equal counts of a, b, and c.

    Use a two dimensional prefix difference:
      ➤ diffAB = countA - countB
      ➤ diffAC = countA - countC

    If (diffAB,diffAC) repeats at i and j → substring is balanced.

    =============================================================
    🔹 Time Complexity : O(n)
    🔹 Space Complexity: O(n)
    -------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Helper to handle two characters
    int helper(string &s, char ch1, char ch2) {

        unordered_map<int,int> mp;
        mp[0] = -1;

        int count1 = 0;
        int count2 = 0;
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {

            // Skip characters not in {ch1, ch2}
            if(s[i] != ch1 && s[i] != ch2) {
                mp.clear();
                mp[0] = i;
                count1 = 0;
                count2 = 0;
                continue;
            }

            if(s[i] == ch1) count1++;
            if(s[i] == ch2) count2++;

            int diff = count1 - count2;

            if(mp.count(diff)) {
                ans = max(ans, i - mp[diff]);
            } else {
                mp[diff] = i;
            }
        }
        return ans;
    }

    int longestBalanced(string &s) {

        int n = s.size();
        int maxLen = 0;

        // Case 1: single character longest run
        int count = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                count++;
            } else {
                maxLen = max(maxLen, count);
                count = 1;
            }
        }
        maxLen = max(maxLen, count);

        // Case 2: two characters
        maxLen = max(maxLen, helper(s,'a','b'));
        maxLen = max(maxLen, helper(s,'a','c'));
        maxLen = max(maxLen, helper(s,'b','c'));

        // Case 3: three characters
        unordered_map<string,int> mp;
        mp["0_0"] = -1;

        int countA = 0, countB = 0, countC = 0;

        for(int i = 0; i < n; i++) {

            if(s[i] == 'a') countA++;
            if(s[i] == 'b') countB++;
            if(s[i] == 'c') countC++;

            int diffAB = countA - countB;
            int diffAC = countA - countC;

            string key = to_string(diffAB) + "_" + to_string(diffAC);

            if(mp.count(key)) {
                maxLen = max(maxLen, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }

        return maxLen;
    }
};



/***************************************************************
*  File Name   : isomorphic_strings.cpp
*  Problem     : Isomorphic Strings
*  Platform    : GeeksforGeeks
*  Difficulty  : Easy
*
*  ------------------------------------------------------------
*  PROBLEM STATEMENT:
*  Given two strings s1 and s2 of equal length, check whether
*  they are isomorphic.
*
*  Two strings are isomorphic if characters in s1 can be
*  replaced to get s2, while:
*   - Order of characters must remain the same
*   - One character maps to exactly one character
*   - No two different characters map to the same character
*
*  Example:
*    s1 = "egg", s2 = "add"  -> true
*    s1 = "foo", s2 = "bar"  -> false
*
***************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {

        /* ----------------------------------------------------
         * STEP 1: Length check
         * ----------------------------------------------------
         * If lengths are different, mapping is impossible.
         */
        if (s1.length() != s2.length())
            return false;

        /* ----------------------------------------------------
         * STEP 2: Maps + pattern vectors
         * ----------------------------------------------------
         * mp1 : maps characters of s1 to unique ids
         * mp2 : maps characters of s2 to unique ids
         *
         * v1  : pattern formed from s1
         * v2  : pattern formed from s2
         */
        unordered_map<char, int> mp1, mp2;
        vector<int> v1, v2;

        int id1 = 0, id2 = 0;

        /* ----------------------------------------------------
         * STEP 3: Build pattern for s1
         * ----------------------------------------------------
         * Each new character gets a new id.
         * Repeated characters reuse the same id.
         *
         * Example: "paper" -> [0,1,0,2,3]
         */
        for (char ch : s1) {
            if (mp1.find(ch) == mp1.end()) {
                mp1[ch] = id1++;
            }
            v1.push_back(mp1[ch]);
        }

        /* ----------------------------------------------------
         * STEP 4: Build pattern for s2
         * ----------------------------------------------------
         * Example: "title" -> [0,1,0,2,3]
         */
        for (char ch : s2) {
            if (mp2.find(ch) == mp2.end()) {
                mp2[ch] = id2++;
            }
            v2.push_back(mp2[ch]);
        }

        /* ----------------------------------------------------
         * STEP 5: Compare patterns
         * ----------------------------------------------------
         * If patterns are identical → strings are isomorphic.
         */
        return v1 == v2;
    }
};

/***************************************************************
*  INTUITION:
*  ------------------------------------------------------------
*  Instead of directly mapping characters, we convert each
*  string into a "pattern representation".
*
*  If two strings produce the same pattern, they are isomorphic.
*
*  This avoids complex bidirectional mapping logic.
*
***************************************************************/

/***************************************************************
*  TIME COMPLEXITY:
*  ------------------------------------------------------------
*  O(n)  where n = length of the string
*
*  SPACE COMPLEXITY:
*  ------------------------------------------------------------
*  O(n)  for maps and pattern vectors
*
***************************************************************/

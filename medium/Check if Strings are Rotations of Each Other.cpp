/***************************************************************
 *
 *  Problem: Check if Strings are Rotations of Each Other
 *
 *  Link:
 *  https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1
 *
 *  Problem Statement:
 *  You are given two strings s1 and s2 of equal length.
 *  Check whether s2 is a rotation of s1.
 *
 *  A string is considered a rotation of another string
 *  if it can be obtained by shifting characters from
 *  the beginning to the end (left rotation) or from
 *  the end to the beginning (right rotation),
 *  without changing the order of characters.
 *
 *  Examples:
 *  Input:  s1 = "abcd", s2 = "cdab"
 *  Output: true
 *
 *  Input:  s1 = "aab", s2 = "aba"
 *  Output: true
 *
 *  Input:  s1 = "abcd", s2 = "acbd"
 *  Output: false
 *
 ***************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
    ===========================
    Approach (Optimal & Clean)
    ===========================

    Key Observation:
    If s2 is a rotation of s1, then s2 must be a substring of (s1 + s1).

    Example:
        s1 = "abcd"
        s2 = "cdab"

        s1 + s1 = "abcdabcd"
        "cdab" exists inside "abcdabcd"

    Steps:
    1. If lengths are different → not possible.
    2. Create a new string temp = s1 + s1.
    3. Check if s2 is a substring of temp.

    Why this works:
    - All possible rotations of s1 appear as substrings
      inside s1 + s1.
*/

class Solution {
  public:
    bool areRotations(string s1, string s2) {

        // Step 1: Length check
        if (s1.length() != s2.length())
            return false;

        // Step 2: Concatenate s1 with itself
        string temp = s1 + s1;

        // Step 3: Check if s2 is substring of temp
        return temp.find(s2) != string::npos;
    }
};

/*
    ===========================
    Time & Space Complexity
    ===========================

    Time Complexity:
    - O(n), where n is length of the string
      (string::find uses efficient algorithms internally)

    Space Complexity:
    - O(n) for storing s1 + s1

    ===========================
    Interview Notes
    ===========================

    ✔ Very common string rotation problem
    ✔ Simple logic but tests observation skills
    ✔ Preferred solution in interviews & contests
    ✔ Avoid manual rotation loops unless asked

    One-liner rule to remember:
    "Rotation problem = substring problem"
*/

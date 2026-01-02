/*
    File Name   : compare_version_numbers.cpp
    Platform    : LeetCode
    Problem     : 165. Compare Version Numbers
    Difficulty  : Medium
    Author      : Saurabh Singh Rajput

    ----------------------------------------------------
    PROBLEM SUMMARY:
    Two version strings are given (e.g. "1.0.12", "1.0.2").
    Each version consists of revisions separated by '.'.
    We must compare each revision numerically (not lexicographically).

    ----------------------------------------------------
    APPROACH USED:
    Two Pointer + ASCII Digit Parsing

    ----------------------------------------------------
    PLATFORM PATTERN:
    - String Parsing
    - Two Pointer Technique
    - Character to Integer conversion using ASCII

    ----------------------------------------------------
    INTUITION:
    - Traverse both version strings simultaneously
    - Extract numbers between dots ('.')
    - Convert characters to integers using:
          num = num * 10 + (ch - '0')
    - Compare each revision immediately
    - Treat missing revisions as 0

    ----------------------------------------------------
    TIME COMPLEXITY : O(n + m)
    SPACE COMPLEXITY: O(1)

    ----------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {

        int n1 = version1.size();
        int n2 = version2.size();

        int i = 0, j = 0;

        // Traverse both strings
        while (i < n1 || j < n2) {

            long long num1 = 0;
            long long num2 = 0;

            // Read revision from version1
            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }

            // Read revision from version2
            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            // Compare current revision
            if (num1 > num2) return 1;
            if (num1 < num2) return -1;

            // Skip dot
            if (i < n1 && version1[i] == '.') i++;
            if (j < n2 && version2[j] == '.') j++;
        }

        return 0;
    }
};

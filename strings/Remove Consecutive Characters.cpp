/***************************************************************
 * Platform   : GeeksforGeeks
 * Question   : Remove Consecutive Characters
 * Link       : https://www.geeksforgeeks.org/problems/consecutive-elements2306/1
 *
 * Problem Description:
 * -------------------------------------------------------------
 * Given a string s, remove all consecutive duplicate characters
 * from the string and return the modified string.
 *
 * Example:
 * Input  : "aabbccdaa"
 * Output : "abcda"
 *
 * Explanation:
 * - Consecutive duplicates are removed.
 * - Only one occurrence of each consecutive group is kept.
 *
 * Constraints:
 * - 1 <= length of string <= 10^5
 * - String contains lowercase English letters
 *
 * Approach Used:
 * -------------------------------------------------------------
 * Two Pointer Technique
 *
 * Intuition:
 * - Traverse the string using index i
 * - Add current character to answer
 * - Skip all next characters which are same as current
 * - Move i to the next different character
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(n)
 ***************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeConsecutiveCharacter(string& s) {
        int n = s.size();
        int i = 0;
        string ans = "";

        while (i < n) {
            // Add current character
            ans += s[i];

            int j = i + 1;

            // Skip all consecutive same characters
            while (j < n && s[i] == s[j]) {
                j++;
            }

            // Move i to next new character
            i = j;
        }

        return ans;
    }
};

/*
----------------------
Example Dry Run:
----------------------
Input  : "aaabbcdd"
i = 0 -> add 'a', skip aa
i = 3 -> add 'b', skip b
i = 4 -> add 'c'
i = 5 -> add 'd', skip d

Output : "abcd"
*/

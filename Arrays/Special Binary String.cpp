/*
    Problem: Special Binary String
    Platform: LeetCode
    Approach: Recursion + Greedy Sorting
    Time Complexity: O(n^2 log n)
    Space Complexity: O(n)

    Author: Saurabh Singh
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
        A special binary string:
        1. Equal number of 1s and 0s
        2. In every prefix, number of 1s >= number of 0s

        This is similar to valid parentheses:
        '1' -> '('
        '0' -> ')'
    */

    string solve(string s) {

        vector<string> specials;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {

            // Count balance like parentheses
            balance += (s[i] == '1') ? 1 : -1;

            // When balance becomes zero -> valid special substring
            if (balance == 0) {

                // Extract inner substring (excluding outer 1 and 0)
                string inner = s.substr(start + 1, i - start - 1);

                // Recursively solve inner part
                specials.push_back("1" + solve(inner) + "0");

                // Move start to next segment
                start = i + 1;
            }
        }

        // Sort in descending order to get lexicographically largest
        sort(specials.begin(), specials.end(), greater<string>());

        // Join all substrings
        string result;
        for (string &str : specials) {
            result += str;
        }

        return result;
    }

    string makeLargestSpecial(string s) {
        return solve(s);
    }
};

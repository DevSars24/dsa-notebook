/*
====================================================
Problem Name : Divide a String Into Groups of Size k
Platform     : LeetCode
Difficulty   : Easy

Problem Link :
https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/

----------------------------------------------------
Problem Description:
You are given a string `s`, an integer `k`, and a character `fill`.

Your task is to divide the string `s` into groups of size `k`.
- The characters are taken from left to right.
- If the last group has fewer than `k` characters,
  append the `fill` character until its size becomes `k`.

Return a vector of strings representing the groups.

----------------------------------------------------
Example:
Input:
s = "abcdefg", k = 3, fill = 'x'

Output:
["abc", "def", "gxx"]

----------------------------------------------------
Approach Used:
1. Traverse the string from left to right.
2. Build groups of size `k` using a temporary string.
3. Whenever the group size reaches `k`, push it into the result.
4. After traversal, if the last group is smaller than `k`,
   pad it with the `fill` character.
5. Return the result vector.

----------------------------------------------------
Time Complexity:
O(n), where n is the length of the string.

Space Complexity:
O(n), for storing the result groups.

----------------------------------------------------
Author Notes:
- Solution uses basic string manipulation.
- No extra data structures required.
- Clean and readable implementation.
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
        vector<string> result;
        string words = "";
        int x = s.size();
        
        // If string size is exactly k
        if (x == k) {
            result.push_back(s);
            return result;
        }

        int y = x / k;   // number of full groups (not explicitly used)
        int z = x % k;   // remainder characters

        // Form groups of size k
        for (int i = 0; i < x; i++) {
            if (i % k == 0 && i != 0) {
                result.push_back(words);
                words.clear();
            }
            words += s[i];
        }

        // Handle last group
        if (z == 0) {
            result.push_back(words);
            return result;
        } else {
            int w = k - z;
            while (w--) {
                words += fill;
            }
            result.push_back(words);
        }

        return result;
    }
};

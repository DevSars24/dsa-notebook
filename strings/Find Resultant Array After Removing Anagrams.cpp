/*
====================================================
LeetCode Problem: 2273. Find Resultant Array After Removing Anagrams
Difficulty: Easy

Problem Link:
https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/

----------------------------------------------------
Problem Description:
You are given a 0-indexed array of strings `words`, where each word consists
of lowercase English letters.

In one operation, select an index `i` such that:
    - 0 < i < words.length
    - words[i] and words[i-1] are anagrams

If the condition is satisfied, delete words[i].

Repeat the operation as long as possible.
Return the final array after all valid operations.

It is guaranteed that the order of deletion does not affect the final result.

----------------------------------------------------
Anagram Definition:
Two strings are anagrams if they contain the same characters
with the same frequencies, irrespective of order.

Example:
"abba" and "baba" → anagrams
"ab" and "abc" → not anagrams

----------------------------------------------------
Approach (Greedy + Filtering):
1. Create a result array to store valid words.
2. Always keep the first word (no previous word to compare).
3. Iterate from index 1 to end:
   - Compare current word with the last word in result.
   - If they are anagrams → skip current word.
   - Otherwise → add current word to result.
4. Return the result array.

Key Insight:
Deletion is not done explicitly.
Skipping insertion effectively removes the word.

----------------------------------------------------
Time Complexity:
Let N = number of words
Let K = maximum length of a word

Anagram check takes O(K)
Total Time: O(N * K)

Space Complexity:
O(K) for frequency maps
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Helper function to check if two strings are anagrams
    bool is_anagram(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;

        unordered_map<char, int> mp1, mp2;

        for (char ch : s1)
            mp1[ch]++;

        for (char ch : s2)
            mp2[ch]++;

        return mp1 == mp2;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;

        // Always keep the first word
        result.push_back(words[0]);

        for (int i = 1; i < words.size(); i++) {
            // Compare with last valid word
            if (is_anagram(words[i], result.back())) {
                continue; // skip anagram
            }
            result.push_back(words[i]);
        }

        return result;
    }
};

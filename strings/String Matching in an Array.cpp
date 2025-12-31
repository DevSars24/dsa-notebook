/*
====================================================
Problem Name : String Matching in an Array
Platform     : LeetCode
Difficulty   : Easy

Problem Link :
https://leetcode.com/problems/string-matching-in-an-array/

----------------------------------------------------
Problem Description:
You are given an array of strings `words`.

A string `words[i]` is considered valid if it is a
substring of another string `words[j]`
where `i != j`.

Return all such strings in any order.

----------------------------------------------------
Example:
Input:
words = ["mass","as","hero","superhero"]

Output:
["as","hero"]

----------------------------------------------------
Approach Used (Brute Force + Substring Check):
1. Compare every word with every other word.
2. Skip comparison when indices are the same.
3. Use `string::find()` to check substring existence.
4. If a word is found as a substring of any other word,
   add it once to the result.
5. Stop further checks for that word to avoid duplicates.

----------------------------------------------------
Time Complexity:
O(n² * k)
where:
- n = number of words
- k = average length of each word

Space Complexity:
O(1) extra space (excluding result vector)

----------------------------------------------------
Key Insight:
The problem asks for existence, not frequency.
Once a word is found as a substring anywhere,
it should be added only once.
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool is_substring(string a, string b) {
        if (b.find(a) != string::npos) {
            return true;
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {

        vector<string> cgpa;
        string wording = "";     
        int n = words.size();

        for (int i = 0; i < n; i++) {

            wording = words[i];
            int j = 0;

            while (j < n) {

                if (i == j) {
                    j++;
                    continue;
                }

                string x = words[j];

                if (is_substring(wording, x)) {
                    cgpa.push_back(wording);
                    break; // avoid duplicates
                }

                j++;
            }
        }

        return cgpa;
    }
};

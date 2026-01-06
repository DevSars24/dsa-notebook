/*
=====================================================
File Name : count_anagrams.cpp
Problem   : Count Occurrences of Anagrams
Platform  : GeeksforGeeks
Difficulty: Medium
=====================================================

PROBLEM STATEMENT:
Given a pattern string `pat` and a text string `txt`,
count the number of substrings in `txt` that are
anagrams of `pat`.

Example:
txt = "forxxorfxdofr"
pat = "for"
Output = 3

-----------------------------------------------------
APPROACH:
Sliding Window + Hash Map (Frequency Count)

Why Sliding Window?
- We need to check all substrings of size = pat.length()
- Sliding window allows O(n) traversal

Why Hash Map?
- To store frequency of characters in pattern
- To efficiently compare current window characters

-----------------------------------------------------
TIME COMPLEXITY : O(N)
SPACE COMPLEXITY: O(1)  (since only 26 lowercase letters)
=====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(string &pat, string &txt) {

        unordered_map<char, int> freq;

        // Step 1: Store frequency of characters of pattern
        for (char ch : pat) {
            freq[ch]++;
        }

        int i = 0, j = 0;
        int k = pat.size();       // Window size
        int count = freq.size(); // Number of unique chars
        int ans = 0;

        // Step 2: Sliding window
        while (j < txt.size()) {

            // Include current character into window
            if (freq.find(txt[j]) != freq.end()) {
                freq[txt[j]]--;
                if (freq[txt[j]] == 0)
                    count--;
            }

            // Step 3: When window size is reached
            if (j - i + 1 == k) {

                // If all characters matched
                if (count == 0)
                    ans++;

                // Remove i-th character from window
                if (freq.find(txt[i]) != freq.end()) {
                    freq[txt[i]]++;
                    if (freq[txt[i]] == 1)
                        count++;
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};

/*
-------------------------
DRY RUN (Example 1):
txt = forxxorfxdofr
pat = for

Window size = 3
Valid anagrams:
"for", "orf", "ofr"

Answer = 3
-------------------------
*/

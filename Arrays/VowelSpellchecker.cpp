/*
=================================================================================
File     : VowelSpellchecker.cpp
Link     : https://leetcode.com/problems/vowel-spellchecker/         <-- LeetCode Problem
Problem  : 966. Vowel Spellchecker
Difficulty: Medium
Language : C++

=================================================================================
PROBLEM SUMMARY
---------------------------------------------------------------------------------
Implement a spell checker that converts query words into their correct forms 
based on a supplied word list, following rules in priority order:
1) Exact Match (case-sensitive)
2) Case-Insensitive Match
3) Vowel Error Match (ignore vowels – a, e, i, o, u)

Return the first matching word in the word list according to the above rules.
If no match, return an empty string.

=================================================================================
EXPLANATION
---------------------------------------------------------------------------------
Approach uses three hash structures:
1) `exactset`           – stores words exactly as in the word list
2) `casemap`            – maps lowercase word → original word (first occurrence)
3) `vowelmap`           – maps vowel-masked lowercase word → original word 
                         (first occurrence, vowels replaced with '*')

For each query:
  - If exact match exists → return it
  - Else lowercase and check casemap
  - Else replace vowels and check vowelmap
  - Else return ""

This ensures O(1) average lookup per query after preprocessing of word list.  
(Preprocessing time O(N * L), query time O(Q * L), where L is average word length.)

=================================================================================
REFERENCE & INTUITION
---------------------------------------------------------------------------------
Rules from problem:
- Exact match → return same word
- Case-insensitive match → first such word in list
- Vowel error match → first word matching vowel pattern
- Nothing matched → return empty string
✔️ First win preserved by storing only first occurrence in maps. :contentReference[oaicite:0]{index=0}

=================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // main containers
    unordered_set<string> exactset;
    unordered_map<string, string> casemap;
    unordered_map<string, string> vowelmap;

    // helper: convert to lowercase
    string toLower(string s) {
        for (char &c : s) {
            c = ::tolower(c);
        }
        return s;
    }

    // helper: replace vowels with '*'
    string maskVowels(string s) {
        for (char &c : s) {
            if (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {

        // clear before use
        exactset.clear();
        casemap.clear();
        vowelmap.clear();

        // build maps
        for (auto &word : wordlist) {
            exactset.insert(word);

            string lower = toLower(word);
            // only first occurrence stored
            if (!casemap.count(lower)) {
                casemap[lower] = word;
            }

            string masked = maskVowels(lower);
            if (!vowelmap.count(masked)) {
                vowelmap[masked] = word;
            }
        }

        vector<string> result;
        for (auto &query : queries) {

            // 1) exact
            if (exactset.count(query)) {
                result.push_back(query);
                continue;
            }

            // 2) case insensitive
            string lowerQ = toLower(query);
            if (casemap.count(lowerQ)) {
                result.push_back(casemap[lowerQ]);
                continue;
            }

            // 3) vowel error
            string vowelQ = maskVowels(lowerQ);
            if (vowelmap.count(vowelQ)) {
                result.push_back(vowelmap[vowelQ]);
                continue;
            }

            // 4) no match
            result.push_back("");
        }

        return result;
    }
};

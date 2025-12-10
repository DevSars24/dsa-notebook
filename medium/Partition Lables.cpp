// ================================================================
// LeetCode Problem: 763. Partition Labels
// Question Link: https://leetcode.com/problems/partition-labels/
// ================================================================
/*
    📝 PROBLEM STATEMENT (Summary)
    ----------------------------------
    You are given a string "s". Your task is to partition it into the
    maximum number of substrings such that **each character appears in
    at most one substring**.

    After concatenating all partitions, the final string must remain
    exactly the same as the original.

    You must return a vector<int> where each element is the size of a
    valid partition.

    Example:
        Input:  s = "ababcbacadefegdehijhklij"
        Output: [9, 7, 8]
*/

// ================================================================
// DRY RUN (Example: "ababcbacadefegdehijhklij")
// ================================================================
/*
    Step 1: Compute last-occurrence index of each character.
    For example:
        'a' -> 8
        'b' -> 5
        'c' -> 7
        ...

    Step 2: Start scanning from i = 0

    Partition 1:
        i = 0 → 'a' → last = 8
        j moves from 0 to 8 updating 'last' using max(...)
        Partition ends at j = 8 → size = 9

    Partition 2:
        i = 9 → 'd' → last = 14
        j moves from 9 to 14
        Partition ends at j = 14 → size = 7

    Partition 3:
        i = 15 → 'h' → last = 23
        j moves from 15 to 23
        Partition ends at j = 23 → size = 8

    Final Result → [9, 7, 8]
*/

// ================================================================
// FULLY DOCUMENTED SOLUTION
// ================================================================
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {

        int n = s.length();
        vector<int> result;  // Stores final partition sizes

        // ------------------------------------------------------------
        // STEP 1: Compute last occurrence of every character
        // ------------------------------------------------------------
        // Since the string contains lowercase letters only, we use
        // a size-26 array to store the last index of each character.
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;  // Update last appearance index
        }

        // ------------------------------------------------------------
        // STEP 2: Create partitions
        // ------------------------------------------------------------
        // We use two pointers:
        // i = start of a partition
        // j = current scanning index
        // end = furthest last occurrence index within the partition
        int i = 0;

        while (i < n) {
            int end = last[s[i] - 'a']; // initial boundary for the partition
            int j = i;

            // Expand the partition boundary based on characters inside it
            while (j < end) {
                end = max(end, last[s[j] - 'a']);
                j++;
            }

            // Now j == end → valid partition formed
            result.push_back(j - i + 1);

            i = j + 1; // move to the next partition start
        }

        return result;
    }
};

// ================================================================
// END OF FILE
// ================================================================

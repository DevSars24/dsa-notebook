/*
Question:
LeetCode - 3170. Clear Stars

Link:
https://leetcode.com/problems/clear-stars/

Problem Summary:
For each '*', delete the leftmost '*' and the lexicographically smallest
non-'*' character to its left.
If multiple such characters exist, delete the rightmost one.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearStars(string s) {

        int n = s.size();

        // Min-heap:
        // 1) smallest character first
        // 2) if characters are same, rightmost index first (using -index)
        priority_queue<
            pair<char,int>,
            vector<pair<char,int>>,
            greater<pair<char,int>>
        > pq;

        for(int i = 0; i < n; i++) {

            if(s[i] >= 'a' && s[i] <= 'z') {
                pq.push({s[i], -i});
            }
            else if(s[i] == '*') {
                if(!pq.empty()) {
                    auto it = pq.top();
                    pq.pop();

                    int idx = -it.second;
                    s[idx] = '*';   // mark removed character
                }
            }
        }

        // Build final string (skip '*')
        string result = "";
        for(char c : s) {
            if(c != '*')
                result.push_back(c);
        }

        return result;
    }
};

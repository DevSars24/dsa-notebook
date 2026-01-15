/*
    LeetCode Problem: Longest Happy String
    Link: https://leetcode.com/problems/longest-happy-string/

    Approach:
    ----------
    - Use a max heap (priority_queue) to always pick the character
      with the highest remaining frequency.
    - Ensure that no character appears more than twice consecutively.
    - If the most frequent character causes violation, pick the next
      most frequent one.

    Time Complexity: O(a + b + c)
    Space Complexity: O(1)   (only 3 characters max in heap)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        // Max heap storing {count, character}
        priority_queue<pair<int, char>> pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans = "";

        while (!pq.empty()) {

            // Take the character with highest remaining count
            auto [count1, ch1] = pq.top();
            pq.pop();

            int n = ans.size();

            // If last two characters are same as current character,
            // we cannot use it again immediately
            if (n >= 2 && ans[n - 1] == ch1 && ans[n - 2] == ch1) {

                // No alternative character available
                if (pq.empty())
                    break;

                // Take second most frequent character
                auto [count2, ch2] = pq.top();
                pq.pop();

                ans.push_back(ch2);
                count2--;

                // Push back if still available
                if (count2 > 0)
                    pq.push({count2, ch2});

                // Push the skipped character back
                pq.push({count1, ch1});
            }
            else {
                // Safe to use the most frequent character
                ans.push_back(ch1);
                count1--;

                if (count1 > 0)
                    pq.push({count1, ch1});
            }
        }

        return ans;
    }
};

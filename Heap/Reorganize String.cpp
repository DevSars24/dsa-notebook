/*
LeetCode: 767. Reorganize String
Link:
https://leetcode.com/problems/reorganize-string/

------------------------------------------------------------
PROBLEM:
Rearrange the string so that no two adjacent characters are the same.
If not possible, return an empty string.

------------------------------------------------------------
APPROACH: GREEDY + MAX HEAP
------------------------------------------------------------

1. Count frequency of each character.
2. If any character frequency > (n+1)/2 → impossible.
3. Use a max heap to always pick the two most frequent characters.
4. Append them alternately and decrease their frequency.
5. Push back if frequency still remains.

------------------------------------------------------------
DRY RUN EXAMPLE:
------------------------------------------------------------
s = "aaabbc"

freq:
a=3, b=2, c=1

Heap:
(3,'a'), (2,'b'), (1,'c')

Step 1:
pop a,b → "ab"
push back a(2), b(1)

Step 2:
pop a,c → "abac"
push back a(1)

Step 3:
pop a,b → "abacab"

Result has no adjacent duplicates.

------------------------------------------------------------
TIME COMPLEXITY:  O(n log 26) ≈ O(n)
SPACE COMPLEXITY: O(26)
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {

        int n = s.length();

        // Step 1: Frequency count
        vector<int> freq(26, 0);
        for(char ch : s) {
            freq[ch - 'a']++;
            if(freq[ch - 'a'] > (n + 1) / 2)
                return "";
        }

        // Step 2: Max heap {frequency, character}
        priority_queue<pair<int,char>> pq;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                pq.push({freq[i], char(i + 'a')});
            }
        }

        string ans = "";

        // Step 3: Greedy selection
        while(pq.size() >= 2) {

            auto p1 = pq.top(); pq.pop();
            auto p2 = pq.top(); pq.pop();

            ans.push_back(p1.second);
            ans.push_back(p2.second);

            p1.first--;
            p2.first--;

            if(p1.first > 0) pq.push(p1);
            if(p2.first > 0) pq.push(p2);
        }

        // Step 4: Last remaining character (if any)
        if(!pq.empty()) {
            ans.push_back(pq.top().second);
        }

        return ans;
    }
};

/*
    File Name : top_k_frequent_words.cpp
    Problem   : LeetCode 692 - Top K Frequent Words
    Approach  : HashMap + Max Heap (Custom Comparator)

    Ordering Rules:
    1) Higher frequency first
    2) If same frequency → lexicographically smaller word first
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        /* -------------------------------------------
           STEP 1: Frequency Count
        --------------------------------------------*/
        unordered_map<string, int> mp;
        for (string &w : words) {
            mp[w]++;
        }

        /* -------------------------------------------
           STEP 2: Custom Comparator
           
           Return true means:
           → element 'a' has LOWER priority than 'b'
        --------------------------------------------*/
        auto cmp = [](const pair<string,int>& a,
                      const pair<string,int>& b) {

            // Case 1: Same frequency → lexicographical order
            if (a.second == b.second)
                return a.first > b.first;   // smaller word first

            // Case 2: Different frequency → higher frequency first
            return a.second < b.second;
        };

        /* -------------------------------------------
           STEP 3: Max Heap with Custom Comparator
        --------------------------------------------*/
        priority_queue<
            pair<string,int>,
            vector<pair<string,int>>,
            decltype(cmp)
        > maxHeap(cmp);

        for (auto &it : mp) {
            maxHeap.push({it.first, it.second});
        }

        /* -------------------------------------------
           STEP 4: Extract Top K Elements
        --------------------------------------------*/
        vector<string> result;
        while (k--) {
            result.push_back(maxHeap.top().first);
            maxHeap.pop();
        }

        return result;
    }
};

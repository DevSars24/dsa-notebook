/*
    File Name : top_k_frequent_elements.cpp
    Problem   : 347. Top K Frequent Elements (LeetCode)
    Approach  : HashMap + Max Heap
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Frequency Map
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }

        // Step 2: Max Heap (frequency, element)
        priority_queue<pair<int, int>> maxHeap;
        for (auto it : mp) {
            maxHeap.push({it.second, it.first});
        }

        // Step 3: Extract top k frequent elements
        vector<int> result;
        while (k--) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};

/*
------------------------------------------------------------
Problem: Majority Element
Platform: GeeksforGeeks
Link: https://www.geeksforgeeks.org/problems/majority-element-1587115620/1

Statement:
Given an array arr[]. Find the majority element in the array.
If no majority element exists, return -1.

A majority element is an element that appears strictly more
than arr.size()/2 times in the array.

------------------------------------------------------------
Approach:
1. Use an unordered_map to count frequency of each element.
2. Traverse the map and check if any element appears more than n/2 times.
3. If found, return that element.
4. Otherwise, return -1.

Time Complexity: O(n)
Space Complexity: O(n)
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;

        // Count frequency
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        // Check majority condition
        for (auto it : freq) {
            if (it.second > n / 2) {
                return it.first;
            }
        }

        return -1;
    }
};

// Driver code (for local testing)
int main() {
    Solution sol;
    vector<int> arr = {1, 1, 2, 1, 3, 5, 1};

    cout << "Majority Element: " << sol.majorityElement(arr) << endl;
    return 0;
}

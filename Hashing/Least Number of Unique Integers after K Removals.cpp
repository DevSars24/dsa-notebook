/*
    Problem: Least Number of Unique Integers after K Removals
    Platform: LeetCode
    Difficulty: Medium

    ---------------------------------------------------------
    🔹 Approach:
    1. Count frequency of each number.
    2. Store (number, frequency) pairs in a vector.
    3. Sort the vector by frequency (ascending).
    4. Remove elements starting from lowest frequency.
    5. If k >= frequency → remove whole number (unique--).
    6. Stop when k < frequency.

    ---------------------------------------------------------
    ⏱ Time Complexity:
    - Frequency count: O(n)
    - Sorting: O(n log n)
    - Removal loop: O(n)
    👉 Overall: O(n log n)

    🧠 Space Complexity:
    - HashMap + vector: O(n)

    ---------------------------------------------------------
    ✔ Key Insight:
    To minimize unique elements, always remove numbers
    with the smallest frequency first.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        unordered_map<int, int> mp;

        // Step 1: Frequency count
        for (int x : arr) {
            mp[x]++;
        }

        // Step 2: Convert map to vector (value, frequency)
        vector<pair<int, int>> v(mp.begin(), mp.end());

        // Step 3: Sort by frequency (ascending)
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        int unique = v.size(); // total unique elements
        int i = 0;

        // Step 4: Remove elements greedily
        while (i < v.size() && k > 0) {
            int freq = v[i].second;

            if (k >= freq) {
                k -= freq;     // remove this number completely
                unique--;      // one unique removed
            } else {
                break;         // can't remove further
            }
            i++;
        }

        return unique;
    }
};

/*
    Example:
    arr = [5,5,4], k = 1
    freq = [(5,2),(4,1)] → sorted → [(4,1),(5,2)]
    remove 4 → k=0 → unique=1

    Output: 1
*/

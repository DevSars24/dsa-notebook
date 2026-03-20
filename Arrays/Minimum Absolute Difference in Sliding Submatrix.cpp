/*
============================================================
📌 Problem: Minimum Absolute Difference in Sliding Submatrix
🔗 Link: https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/

👨‍💻 Author: Saurabh Singh Rajput

------------------------------------------------------------
🧠 Intuition:

For every k x k submatrix:
1. Collect all elements
2. Sort them (using set -> auto sorted)
3. Find minimum absolute difference between adjacent elements

Why adjacent?
👉 Because in sorted order, closest numbers are neighbors.

------------------------------------------------------------
⚙️ Approach:

- Iterate over all possible k x k windows
- Use a set to store elements (sorted automatically)
- Traverse set and compute min difference

------------------------------------------------------------
⏱️ Complexity:

Let:
m = rows, n = cols

Total windows = (m-k+1)*(n-k+1)

For each window:
- Insert k*k elements → O(k² log k²)
- Traverse set → O(k²)

👉 Total:
O((m-k+1)*(n-k+1) * k² log k)

------------------------------------------------------------
🚀 Optimization Note:

This is brute-force-ish.
Can be optimized using:
- Sliding window + multiset
- Frequency arrays (if constraints small)

============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        // Result matrix
        vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1));

        // Traverse all k x k submatrices
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                set<int> st;

                // Collect elements of current window
                for (int r = i; r < i + k; r++) {
                    for (int c = j; c < j + k; c++) {
                        st.insert(grid[r][c]);
                    }
                }

                // Compute minimum absolute difference
                int minDiff = INT_MAX;

                auto it = st.begin();
                auto prev = it;
                it++;

                while (it != st.end()) {
                    minDiff = min(minDiff, abs(*it - *prev));
                    prev = it;
                    it++;
                }

                // Edge case: if only one unique element
                if (minDiff == INT_MAX) minDiff = 0;

                result[i][j] = minDiff;
            }
        }

        return result;
    }
};

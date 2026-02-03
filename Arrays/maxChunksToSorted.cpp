/**
 * @file maxChunksToSorted.cpp
 * @author Saurabh
 * @brief Finds the maximum number of chunks into which the array can be split
 *        so that sorting each chunk individually results in a fully sorted array.
 *
 * Approach:
 * ----------
 * 1. Prefix Maximum Array:
 *    prefixMax[i] stores the maximum element from index 0 to i.
 *
 * 2. Suffix Minimum Array:
 *    suffixMin[i] stores the minimum element from index i to n-1.
 *
 * 3. Partition Logic:
 *    A valid chunk boundary exists at index i if:
 *        max(arr[0 ... i-1]) < min(arr[i ... n-1])
 *
 * Time Complexity:
 * ----------------
 * O(n)
 *
 * Space Complexity:
 * -----------------
 * O(n)
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        // prefixMax[i] = max element from index 0 to i
        vector<int> prefixMax(arr.begin(), arr.end());

        // suffixMin[i] = min element from index i to n-1
        vector<int> suffixMin(arr.begin(), arr.end());

        // Build prefix maximum array
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i], prefixMax[i - 1]);
        }

        // Build suffix minimum array
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i], suffixMin[i + 1]);
        }

        int chunks = 0;

        // Count valid partitions
        for (int i = 0; i < n; i++) {
            int leftMax  = (i > 0) ? prefixMax[i - 1] : -1;
            int rightMin = suffixMin[i];

            if (leftMax < rightMin) {
                chunks++;
            }
        }

        return chunks;
    }
};

/***************************************************************
 * Problem: Minimum Distance Between Three Equal Elements II
 * Platform: LeetCode
 * Link: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/
 *
 * -------------------------------------------------------------
 * 🧠 Problem Description:
 * Given an integer array `nums`, find the minimum distance 
 * between any three equal elements.
 *
 * The distance is defined as:
 *     distance = 2 * (k - i)
 * where:
 *     i = index of first occurrence
 *     k = index of third occurrence
 *
 * We need to find three indices (i < j < k) such that:
 *     nums[i] == nums[j] == nums[k]
 *
 * Return:
 * - Minimum possible distance
 * - If no such triplet exists, return -1
 *
 * -------------------------------------------------------------
 * 💡 Approach:
 *
 * 1. Use a hash map to store indices of each number.
 *    mp[value] → vector of indices where this value appears
 *
 * 2. Traverse the array:
 *    - For each element, store its index
 *    - If the same number appears at least 3 times:
 *         → Take last 3 occurrences
 *         → Compute distance using:
 *               distance = 2 * (k - i)
 *
 * 3. Keep updating the minimum result
 *
 * 4. If no valid triplet found → return -1
 *
 * -------------------------------------------------------------
 * ⏱ Time Complexity:
 * O(n) → single pass through array
 *
 * 🧠 Space Complexity:
 * O(n) → storing indices in hashmap
 *
 ***************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        // Hash map to store indices of each number
        unordered_map<int, vector<int>> mp;

        int result = INT_MAX;

        // Traverse array
        for (int k = 0; k < n; k++) {

            // Store current index
            mp[nums[k]].push_back(k);

            // If at least 3 occurrences exist
            if (mp[nums[k]].size() >= 3) {

                vector<int> &vec = mp[nums[k]];
                int size = vec.size();

                // First of last 3 occurrences
                int i = vec[size - 3];

                // Compute distance
                int distance = 2 * (k - i);

                // Update minimum result
                result = min(result, distance);
            }
        }

        // If no valid triplet found
        return (result == INT_MAX) ? -1 : result;
    }
};

/***************************************************************
 * ✅ Example:
 *
 * Input:
 * nums = [1,2,1,1,3]
 *
 * Indices of 1 → [0,2,3]
 * distance = 2 * (3 - 0) = 6
 *
 * Output:
 * 6
 *
 ***************************************************************/

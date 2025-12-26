/************************************************************
 * Problem: Delete Array Elements
 * Platform: GeeksforGeeks
 * Problem Link:
 * https://www.geeksforgeeks.org/problems/
 * delete-array-elements-which-are-smaller-than-next-or-
 * become-smaller3115/1
 *
 * ----------------------------------------------------------
 * Problem Statement:
 * Given an array arr[] and an integer k.
 * Delete exactly k elements such that:
 *  - An element arr[i] is deleted if arr[i] < arr[i+1]
 *  - After deletion, new adjacent elements may also satisfy
 *    the condition, so the process continues.
 *
 * ----------------------------------------------------------
 * Key Insight:
 * Although the problem does NOT explicitly ask to maximize
 * the array, following the deletion rule greedily results in
 * keeping larger elements towards the left.
 *
 * Hence, the optimal strategy is:
 *  - Always delete the previous smaller element when a larger
 *    element is encountered.
 *
 * ----------------------------------------------------------
 * Approach (Greedy + Stack):
 * 1. Traverse the array from left to right.
 * 2. Maintain a stack to store valid elements.
 * 3. While:
 *      - stack is not empty
 *      - deletions < k
 *      - top of stack < current element
 *    → pop from stack (delete smaller element).
 * 4. Push current element into stack.
 * 5. If deletions are still left, remove elements from the end.
 * 6. Convert stack back to vector (maintaining order).
 *
 * ----------------------------------------------------------
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 *
 * ----------------------------------------------------------
 * Pattern:
 * Greedy + Monotonic Stack
 * (Same family as "Remove K Digits")
 ************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deleteElement(vector<int>& arr, int k) {

        stack<int> s;
        int deleted = 0;

        for (int x : arr) {

            // Delete previous smaller elements greedily
            while (!s.empty() && deleted < k && s.top() < x) {
                s.pop();
                deleted++;
            }

            s.push(x);
        }

        // If deletions still left, remove from the end
        while (deleted < k && !s.empty()) {
            s.pop();
            deleted++;
        }

        // Convert stack to vector (preserve order)
        vector<int> result(s.size());
        for (int i = result.size() - 1; i >= 0; i--) {
            result[i] = s.top();
            s.pop();
        }

        return result;
    }
};

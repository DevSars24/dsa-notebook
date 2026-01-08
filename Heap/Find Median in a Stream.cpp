/*
    Problem: Find Median in a Stream
    Link   : https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

    ------------------------------------------------------------
    INTUITION (CORE IDEA):
    ------------------------------------------------------------
    We maintain TWO HEAPS:

    1️⃣ Max Heap (left side)
       - Stores the smaller half of numbers
       - Top = largest element of the smaller half

    2️⃣ Min Heap (right side)
       - Stores the larger half of numbers
       - Top = smallest element of the larger half

    ------------------------------------------------------------
    INVARIANTS (RULES):
    ------------------------------------------------------------
    ✔ Size difference between heaps ≤ 1
    ✔ MaxHeap can have at most 1 extra element
    ✔ All elements in maxHeap ≤ all elements in minHeap

    ------------------------------------------------------------
    MEDIAN LOGIC:
    ------------------------------------------------------------
    If sizes are equal:
        median = (maxHeap.top() + minHeap.top()) / 2

    If sizes are NOT equal:
        median = maxHeap.top()

    ------------------------------------------------------------
    TIME COMPLEXITY:
    ------------------------------------------------------------
    Each insertion: O(log N)
    Total: O(N log N)

    ------------------------------------------------------------
    SPACE COMPLEXITY:
    ------------------------------------------------------------
    O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> getMedian(vector<int> &arr) {

        vector<double> result;

        // Max heap for left half
        priority_queue<int> maxHeap;

        // Min heap for right half
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int x : arr) {

            // Step 1: Insert element
            if (maxHeap.empty() || x <= maxHeap.top()) {
                maxHeap.push(x);
            } else {
                minHeap.push(x);
            }

            // Step 2: Balance heaps
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // Step 3: Find median
            if (maxHeap.size() == minHeap.size()) {
                double median = (maxHeap.top() + minHeap.top()) / 2.0;
                result.push_back(median);
            } else {
                result.push_back(maxHeap.top());
            }
        }

        return result;
    }
};

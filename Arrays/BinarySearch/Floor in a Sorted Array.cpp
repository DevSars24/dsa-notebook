/*
====================================================
Problem: Floor in a Sorted Array
Platform: GeeksforGeeks
Link: https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

Problem Statement:
Given a sorted array arr[] and an integer x, find the index (0-based)
of the largest element in arr[] that is less than or equal to x.
This element is called the floor of x.

If such an element does not exist, return -1.

Note:
If multiple occurrences of the floor of x exist,
return the index of the LAST occurrence.

----------------------------------------------------
Examples:
Input:  arr = [1, 2, 8, 10, 10, 12, 19], x = 5
Output: 1

Input:  arr = [1, 2, 8, 10, 10, 12, 19], x = 11
Output: 4

Input:  arr = [1, 2, 8, 10, 10, 12, 19], x = 0
Output: -1
----------------------------------------------------

Approach:
- Use Binary Search (array is sorted)
- Maintain an answer variable
- If arr[mid] <= x:
    - update answer
    - move right to find last occurrence
- Else:
    - move left

Time Complexity: O(log n)
Space Complexity: O(1)
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFloor(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= x) {
                ans = mid;      // possible floor found
                low = mid + 1;  // move right for last occurrence
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

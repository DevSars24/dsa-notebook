/*
================================================================================
Problem: Search in a Rotated Sorted Array
GeeksforGeeks Link:
https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1
================================================================================

Given an array arr[] of distinct elements, which was initially sorted in
ascending order but then rotated at some unknown pivot, the task is to find
the index of a target key.  If the key is not present in the array, return -1.

Expected Time Complexity: O(log N)
Expected Auxiliary Space: O(1)

Approach:
1. Use a modified binary search.
2. At each step check if the left or right half is sorted.
3. Based on which half is sorted, decide where the target may lie.
4. Continue until the target is found or search space is exhausted.

Example:
Input: arr = [5,6,7,8,9,10,1,2,3], key = 3
Output: 8

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int key) {
        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If the mid element is the target
            if (arr[mid] == key)
                return mid;

            // If the left half is sorted
            if (arr[low] <= arr[mid]) {
                if (key >= arr[low] && key <= arr[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // Otherwise, the right half is sorted
            else {
                if (key >= arr[mid] && key <= arr[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;  // Not found
    }
};

int main() {
    Solution sol;
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;
    int index = sol.search(arr, key);
    cout << "Index of " << key << " is: " << index << endl;
    return 0;
}

/*
====================================================
Problem: Merge Sort
Platform: Coding Ninjas (Code360)
Link: https://www.naukri.com/code360/problems/merge-sort_920442

Description:
Given an array, sort it using the Merge Sort algorithm.

Approach:
- Divide the array into two halves
- Recursively sort both halves
- Merge the two sorted halves using i & j pointers

Time Complexity: O(n log n)
Space Complexity: O(n)

This problem helps in understanding:
- Recursion flow
- Divide and Conquer
- Core merge logic used in harder problems
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int i = l;
    int j = m + 1;
    vector<int> temp;

    // Merge two sorted halves
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    // Remaining elements
    while (i <= m) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);

    // Copy back to original array
    for (int k = 0; k < temp.size(); k++) {
        arr[l + k] = temp[k];
    }
}

void mergeSortHelper(vector<int>& arr, int l, int r) {
    if (l >= r) return;

    int mid = l + (r - l) / 2;

    mergeSortHelper(arr, l, mid);
    mergeSortHelper(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

void mergeSort(vector<int>& arr, int n) {
    mergeSortHelper(arr, 0, n - 1);
}

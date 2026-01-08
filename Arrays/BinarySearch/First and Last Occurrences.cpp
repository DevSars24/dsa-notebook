/*
    Problem: First and Last Occurrences (GeeksforGeeks)

    Given a sorted array (may contain duplicates),
    find the first and last occurrence of element x.

    If x is not present, return {-1, -1}

    This file contains TWO APPROACHES:

    1) Linear Scan (O(n)) – Simple & intuitive
    2) Binary Search (O(log n)) – Optimized approach
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /* -------------------------------------------------
       APPROACH 1: LINEAR SCAN
       Time  : O(n)
       Space : O(1)
    ---------------------------------------------------*/
    vector<int> firstLastLinear(vector<int>& arr, int x) {
        int first = -1, last = -1;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) {
                if (first == -1) first = i; // first time seen
                last = i;                   // keep updating last
            }
        }

        return {first, last};
    }


    /* -------------------------------------------------
       APPROACH 2: BINARY SEARCH
       Time  : O(log n)
       Space : O(1)
    ---------------------------------------------------*/

    int firstOccurrence(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x) {
                ans = mid;        // possible answer
                high = mid - 1;   // move left
            }
            else if (arr[mid] < x) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int lastOccurrence(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x) {
                ans = mid;        // possible answer
                low = mid + 1;    // move right
            }
            else if (arr[mid] < x) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> firstLastBinary(vector<int>& arr, int x) {
        return { firstOccurrence(arr, x), lastOccurrence(arr, x) };
    }


    /* -------------------------------------------------
       GFG DRIVER FUNCTION (Binary Search preferred)
    ---------------------------------------------------*/
    vector<int> find(vector<int>& arr, int x) {
        // return firstLastLinear(arr, x);   // brute force
        return firstLastBinary(arr, x);      // optimized
    }
};

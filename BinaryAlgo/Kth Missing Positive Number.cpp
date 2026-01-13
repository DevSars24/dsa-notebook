/*
===============================================================================
Problem: Kth Missing Positive Number
Link: https://leetcode.com/problems/kth-missing-positive-number/

Difficulty: Easy
Platform: LeetCode

-------------------------------------------------------------------------------
Problem Statement:
Given an array arr[] of strictly increasing positive integers and an integer k,
return the kth positive integer that is missing from this array.

-------------------------------------------------------------------------------
Approach (Linear Scan – Counting Missing Numbers):

- Start from number = 1
- Traverse the array using index i
- If current number exists in the array → move forward
- If it does NOT exist → it is a missing number → decrement k
- Continue until k becomes 0
- If array finishes but k is still left, keep incrementing numbers

-------------------------------------------------------------------------------
Why This Works:
- The array is sorted and strictly increasing
- We simulate the natural number sequence and count missing values
- Simple, intuitive, and passes all constraints for this problem

-------------------------------------------------------------------------------
Time Complexity:
O(n + k)

Space Complexity:
O(1)

-------------------------------------------------------------------------------
Example:
Input: arr = [2,3,4,7,11], k = 5
Missing numbers: 1,5,6,8,9
Output: 9
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0;
        int num = 1;

        // Traverse numbers while array elements remain and k > 0
        while (i < n && k > 0) {
            if (arr[i] == num) {
                i++;            // number exists in array
            } else {
                k--;            // missing number found
            }
            num++;
        }

        // If kth missing number is beyond array range
        while (k > 0) {
            num++;
            k--;
        }

        return num - 1;
    }
};

// Optional main function for local testing
int main() {
    Solution sol;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout << "Kth missing number: " << sol.findKthPositive(arr, k) << endl;
    return 0;
}

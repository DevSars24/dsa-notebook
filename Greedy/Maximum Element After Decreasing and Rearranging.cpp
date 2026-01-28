/*
====================================================
Platform   : LeetCode
Problem    : Maximum Element After Decreasing and Rearranging
Link       : https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

Difficulty : Medium
Language   : C++

----------------------------------------------------
Problem Summary:
----------------------------------------------------
You are given an array of positive integers.
You can rearrange the array and decrement elements
any number of times such that:

- The first element becomes 1
- The difference between adjacent elements is at most 1

Return the maximum possible value of the last element.

----------------------------------------------------
Approach (Greedy + Sorting):
----------------------------------------------------
1. Sort the array.
2. Set the first element to 1 (minimum allowed).
3. Traverse the array:
   - If the difference between current and previous
     element is more than 1, adjust current element
     to previous + 1.
4. Keep track of the maximum value obtained.

This greedy approach ensures the array remains valid
while maximizing the last element.

----------------------------------------------------
Time Complexity  : O(n log n)
Space Complexity : O(1) (ignoring sort space)
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        arr[0] = 1;

        int maximum = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] > 1) {
                arr[i] = arr[i - 1] + 1;
            }
            maximum = max(maximum, arr[i]);
        }

        return maximum;
    }
};

int main() {
    vector<int> arr = {2, 2, 1, 2, 1};
    Solution obj;
    cout << obj.maximumElementAfterDecrementingAndRearranging(arr);
    return 0;
}

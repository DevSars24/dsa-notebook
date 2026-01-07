/*
=========================================================
GFG: Largest Subarray of 0s and 1s
Link:
https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1

---------------------------------------------------------
PROBLEM STATEMENT:
---------------------------------------------------------
Given a binary array arr[], find the length of the
largest subarray with equal number of 0s and 1s.

---------------------------------------------------------
KEY IDEA:
---------------------------------------------------------
Convert the problem into a ZERO-SUM subarray problem.

---------------------------------------------------------
INTUITION:
---------------------------------------------------------
Replace:
0 -> -1
1 -> +1

Now,
equal number of 0s and 1s
=> sum of that subarray = 0

So the task becomes:
Find the longest subarray with sum = 0

---------------------------------------------------------
APPROACH (Prefix Sum + HashMap):
---------------------------------------------------------
1. Traverse the array
2. Maintain prefix sum
3. If prefix sum becomes 0:
   - subarray [0...i] is valid
4. If same prefix sum appears again:
   - subarray between those indices has sum 0
5. Store FIRST occurrence of each prefix sum

---------------------------------------------------------
TIME COMPLEXITY:
---------------------------------------------------------
O(n)

---------------------------------------------------------
SPACE COMPLEXITY:
---------------------------------------------------------
O(n)

=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLen(vector<int> &arr) {

        unordered_map<int, int> mp; // prefixSum -> first index
        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {

            // Convert 0 to -1, 1 to +1
            sum += (arr[i] == 0 ? -1 : 1);

            // If sum becomes 0, subarray [0..i] is valid
            if (sum == 0) {
                maxLen = i + 1;
            }

            // If same prefix sum seen before
            if (mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            }
            // Store first occurrence only
            else {
                mp[sum] = i;
            }
        }

        return maxLen;
    }
};

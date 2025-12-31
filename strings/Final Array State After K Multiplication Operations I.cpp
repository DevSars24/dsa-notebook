/*
------------------------------------------------------------
LeetCode: Final Array State After K Multiplication Operations I
Platform  : LeetCode
Language  : C++
Approach  : Brute Force (Linear Scan)
------------------------------------------------------------

Idea:
- Har operation mein array ka minimum element find karo
- Us minimum element ko multiplier se multiply karo
- Ye process k times repeat karo
- Final array return karo

Time Complexity:
- O(k * n)  (har step par min find kar rahe hain)

Space Complexity:
- O(1) extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Function to find index of minimum element
    int min(vector<int>& ans) {

        int n = ans.size();
        int minindex = 0;

        for (int i = 1; i < n; i++) {
            if (ans[minindex] > ans[i]) {
                minindex = i;
            }
        }
        return minindex;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        while (k--) {
            int minindex = min(nums);
            nums[minindex] = multiplier * nums[minindex];
        }

        return nums;
    }
};




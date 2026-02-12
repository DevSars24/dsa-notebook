#include <bits/stdc++.h>
using namespace std;

/*
    LEETCODE 78 - SUBSETS
    Link: https://leetcode.com/problems/subsets/
    
    Intuition:
    Every element has 2 choices:
        1) Include
        2) Exclude
    
    Total subsets = 2^n
*/

class Solution {
public:

    /* ==========================
        1️⃣ Backtracking Method
       ========================== */
    void backtrack(int idx, vector<int>& nums, vector<int>& temp,
                   vector<vector<int>>& result) {
        
        if (idx >= nums.size()) {
            result.push_back(temp);
            return;
        }

        // Include current element
        temp.push_back(nums[idx]);
        backtrack(idx + 1, nums, temp, result);

        // Backtrack
        temp.pop_back();

        // Exclude current element
        backtrack(idx + 1, nums, temp, result);
    }

    vector<vector<int>> subsetsBacktracking(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(0, nums, temp, result);
        return result;
    }


    /* ==========================
        2️⃣ Bitmask Method
       ========================== */
    vector<vector<int>> subsetsBitmask(vector<int>& nums) {

        int n = nums.size();
        int total = 1 << n;   // 2^n
        vector<vector<int>> result;

        for (int mask = 0; mask < total; mask++) {
            vector<int> temp;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    temp.push_back(nums[i]);
                }
            }

            result.push_back(temp);
        }

        return result;
    }


    /* ==========================
        3️⃣ Iterative Method
       ========================== */
    vector<vector<int>> subsetsIterative(vector<int>& nums) {

        vector<vector<int>> result = {{}};

        for (int num : nums) {
            int size = result.size();

            for (int i = 0; i < size; i++) {
                vector<int> temp = result[i];
                temp.push_back(num);
                result.push_back(temp);
            }
        }

        return result;
    }
};


/* ==========================
        Helper Print Function
   ========================== */
void printSubsets(vector<vector<int>>& subsets) {
    for (auto& subset : subsets) {
        cout << "{ ";
        for (auto num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }
}


int main() {

    vector<int> nums = {1, 2, 3};
    Solution obj;

    cout << "===== Backtracking =====\n";
    vector<vector<int>> ans1 = obj.subsetsBacktracking(nums);
    printSubsets(ans1);

    cout << "\n===== Bitmask =====\n";
    vector<vector<int>> ans2 = obj.subsetsBitmask(nums);
    printSubsets(ans2);

    cout << "\n===== Iterative =====\n";
    vector<vector<int>> ans3 = obj.subsetsIterative(nums);
    printSubsets(ans3);

    return 0;
}

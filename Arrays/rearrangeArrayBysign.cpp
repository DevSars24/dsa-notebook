#include <iostream>
#include <vector>
using namespace std;

/*
 Problem:
 Rearrange the array such that positive and negative numbers
 appear alternatively, starting with a positive number.

 Constraints guarantee:
 - Equal number of positive and negative elements
 - Order among positives and negatives should be preserved
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Separate positives and negatives
        vector<int> posArray;
        vector<int> negArray;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                posArray.push_back(nums[i]);
            else
                negArray.push_back(nums[i]);
        }

        // Step 2: Merge alternately
        vector<int> result;
        for (int i = 0; i < posArray.size(); i++) {
            result.push_back(posArray[i]);
            result.push_back(negArray[i]);
        }

        return result;
    }
};

// -------- Driver Code (for local testing) --------
int main() {
    Solution sol;

    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> ans = sol.rearrangeArray(nums);

    cout << "Rearranged Array: ";
    for (int x : ans)
        cout << x << " ";

    return 0;
}

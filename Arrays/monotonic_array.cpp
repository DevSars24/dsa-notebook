#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {

        bool increasing = false;
        bool decreasing = false;

        // check adjacent elements
        for (int i = 0; i < nums.size() - 1; i++) {

            if (nums[i] < nums[i + 1])
                increasing = true;

            if (nums[i] > nums[i + 1])
                decreasing = true;
        }

        // if both true → not monotonic
        if (increasing && decreasing)
            return false;

        return true;
    }
};

// -------- Driver code (for local testing) --------
int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 2, 3};
    vector<int> nums2 = {6, 5, 4, 4};
    vector<int> nums3 = {1, 3, 2};

    cout << sol.isMonotonic(nums1) << endl; // 1 (true)
    cout << sol.isMonotonic(nums2) << endl; // 1 (true)
    cout << sol.isMonotonic(nums3) << endl; // 0 (false)

    return 0;
}

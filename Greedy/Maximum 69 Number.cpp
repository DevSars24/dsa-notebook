/**
 * Problem: Maximum 69 Number
 * Platform: LeetCode
 * Link: https://leetcode.com/problems/maximum-69-number/
 * * Description:
 * You are given a positive integer num consisting only of digits 6 and 9.
 * Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).
 */

#include <iostream>
#include <cmath>

class Solution {
public:
    /**
     * Approach: 
     * To get the maximum number, we need to change the left-most '6' into a '9'.
     * We iterate through the digits to find the highest place value where a '6' exists.
     */
    int maximum69Number (int num) {
        int placevalue = 0;
        int placevaluesix = -1;
        int temp = num;

        // Traverse the number from right to left
        while(temp > 0){
            int remain = temp % 10;

            // Every time we find a 6, update placevaluesix.
            // Since we move right to left, the last 6 found will be the most significant one (left-most).
            if(remain == 6) {
                placevaluesix = placevalue;
            }

            temp = temp / 10;
            placevalue++;
        }

        // If no 6 was found, return the original number
        if(placevaluesix == -1){
            return num;
        }

        // Add 3 * 10^placevalue to change the 6 to a 9 (e.g., 60 + 30 = 90)
        return num + 3 * pow(10, placevaluesix);
    }
};

int main() {
    Solution sol;
    int testNum = 9669;
    int result = sol.maximum69Number(testNum);
    
    std::cout << "Original: " << testNum << std::endl;
    std::cout << "Maximum:  " << result << std::endl; // Expected: 9969
    
    return 0;
}

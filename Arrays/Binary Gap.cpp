/*****************************************************************************************
 * Problem: 868. Binary Gap
 * Platform: LeetCode
 * Difficulty: Easy
 *
 * Description:
 * Given a positive integer n, return the longest distance between two
 * consecutive 1's in the binary representation of n.
 * If there are fewer than two 1's, return 0.
 *
 * Example:
 * Input: 22
 * Binary: 10110
 * Output: 2
 *
 *****************************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:

    /*
     * Approach Used:
     * 1. Convert number into binary representation and store in vector.
     * 2. Reverse the vector to get correct MSB → LSB order.
     * 3. Store indices of all 1s in a stack.
     * 4. Pop consecutive indices and compute maximum difference.
     *
     * Time Complexity:
     *   O(log n)   → number of bits
     *
     * Space Complexity:
     *   O(log n)   → storing binary + stack
     */

    int binaryGap(int n) {
        
        int count = 0;
        vector<int> binary;

        // Step 1: Store binary representation
        while(n > 0){
            int r = n % 2;
            n = n / 2;
            binary.push_back(r);
        }

        // Step 2: Reverse to correct order
        reverse(binary.begin(), binary.end());

        int x = binary.size();
        stack<int> st;

        // Step 3: Store indices of 1s
        for(int i = 0; i < x; i++){
            if(binary[i] == 1){
                st.push(i);
            }
        }

        // If less than two 1s, no gap possible
        if(st.size() < 2){
            return 0;
        }

        // Step 4: Compute maximum distance
        while(st.size() > 1){

            int current = st.top();
            st.pop();

            int previous = st.top();
            count = max(count, current - previous);
        }

        return count;
    }
};


/*****************************************************************************************
 * Interview Insight:
 *
 * ✔ This approach demonstrates:
 *   - Understanding of binary conversion
 *   - Use of STL (vector, stack, reverse)
 *   - Index-based gap calculation
 *
 * ✔ Can be optimized further using bit manipulation (O(1) space),
 *   but this solution is logically correct and clean.
 *
 *****************************************************************************************/

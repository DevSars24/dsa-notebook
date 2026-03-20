/*
===========================================================
📌 Problem: Complement of Base 10 Integer
🔗 Link: https://leetcode.com/problems/complement-of-base-10-integer/

👨‍💻 Author: Saurabh Singh
📅 Date: 20 March 2026

===========================================================
🧠 Problem Understanding:

Given an integer `n`, return its bitwise complement.

The complement of a number is obtained by flipping all bits
in its binary representation (0 -> 1, 1 -> 0).

Example:
Input: 5  (binary: 101)
Output: 2 (binary: 010)

===========================================================
💡 Approach:

1. Edge Case:
   - If n == 0 → return 1
     (because binary of 0 is "0", flipping → "1")

2. Iterate through each bit of n:
   - Extract last bit using: n % 2
   - Flip it using: !r
   - Add to result using: (2^position)

3. Move to next bit:
   - n = n / 2

4. Continue until n becomes 0

===========================================================
⚙️ Time Complexity:
O(log n) → number of bits in n

⚙️ Space Complexity:
O(1)

===========================================================
🚀 Optimizations (Interview Insight):

Instead of using pow(2, counter), we can use bit shifting:
    (1 << counter)

Even better approach:
    Use mask to flip bits directly.

===========================================================
🧪 Code:
===========================================================
*/

class Solution {
public:
    int bitwiseComplement(int n) {

        // Edge Case
        if(n == 0) {
            return 1;
        }

        int counter = 0;
        int result = 0;

        while(n) {
            int r = n % 2;

            // Flip bit and add to result
            result += (1 << counter) * (!r);

            counter++;
            n = n / 2;
        }

        return result;
    }
};

/*
===========================================================
🔥 Alternate Optimized Approach (Mask Based):

int bitwiseComplement(int n) {
    if (n == 0) return 1;

    int mask = 0;
    int temp = n;

    while (temp) {
        mask = (mask << 1) | 1;
        temp >>= 1;
    }

    return (~n) & mask;
}

===========================================================
✨ Key Takeaways:

✔ Bit manipulation is crucial for optimization  
✔ Always handle edge cases (like n = 0)  
✔ Prefer bitwise operators over pow() in interviews  

===========================================================
*/

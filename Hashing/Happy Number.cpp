/*
------------------------------------------------------------
Platform   : LeetCode
Problem    : 202. Happy Number
Link       : https://leetcode.com/problems/happy-number/
Difficulty : Easy (Conceptually MEDIUM)
------------------------------------------------------------

🧠 Core Intuition:
A number is HAPPY if the process of:
→ replacing it with the sum of squares of its digits
eventually reaches 1.

If during this process, any number repeats,
it means the process is stuck in a CYCLE
and will never reach 1.

------------------------------------------------------------
🔑 Key Concept:
Cycle Detection using Hashing (unordered_set)

Question this problem really asks:
"Have I seen this number before?"

------------------------------------------------------------
🛠️ Approach:
1. Use an unordered_set to store already seen numbers.
2. Repeat the digit-square-sum process.
3. If number becomes 1 → Happy Number.
4. If a number repeats → Cycle detected → Not Happy.

------------------------------------------------------------
⏱ Time Complexity:
O(log n) per iteration, very small constant cycles.

💾 Space Complexity:
O(log n) for storing seen numbers.

------------------------------------------------------------
*/

class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> seen;

        while(n != 1){

            // Cycle detected
            if(seen.count(n)) return false;
            seen.insert(n);

            int sum = 0;
            while(n > 0){
                int d = n % 10;
                sum += d * d;
                n /= 10;
            }

            n = sum;
        }

        return true;
    }
};

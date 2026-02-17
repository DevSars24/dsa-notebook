/*
============================================================
Problem Name  : Binary Watch
Platform      : LeetCode
Problem Link  : https://leetcode.com/problems/binary-watch/
Difficulty    : Easy
Language      : C++
Author        : Saurabh Singh
============================================================

🔹 Problem Statement:
A binary watch has 4 LEDs for hours (0–11) and 6 LEDs for minutes (0–59).
Each LED represents a binary value.

Given an integer turnedOn, return all possible times the watch could represent
with exactly turnedOn LEDs turned on.

------------------------------------------------------------
🔹 Intuition:

Each time consists of:
- Hour  (0 to 11)
- Minute (0 to 59)

We need:
count_of_1_bits(hour) + count_of_1_bits(minute) == turnedOn

We use:
__builtin_popcount(x)
→ Counts number of 1 bits in binary representation of x.

------------------------------------------------------------
🔹 Approach (Brute Force Simulation):

1. Iterate through all possible hours (0 to 11).
2. Iterate through all possible minutes (0 to 59).
3. Count total number of 1 bits.
4. If equal to turnedOn → store formatted time.
5. Return result list.

Total combinations = 12 × 60 = 720
Which is very small → brute force is efficient.

------------------------------------------------------------
🔹 Time Complexity:
O(12 × 60) = O(720) ≈ O(1)

🔹 Space Complexity:
O(k) where k = number of valid times stored.

============================================================
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {

        vector<string> result;

        // Loop through all possible hours (0–11)
        for(int HH = 0; HH <= 11; HH++) {

            // Loop through all possible minutes (0–59)
            for(int MM = 0; MM <= 59; MM++) {

                // Count total number of 1 bits
                if(__builtin_popcount(HH) +
                   __builtin_popcount(MM) == turnedOn) {

                    // Convert hour to string
                    string hour = to_string(HH);

                    // Add leading zero for minutes if needed
                    string minute;
                    if(MM < 10)
                        minute = "0" + to_string(MM);
                    else
                        minute = to_string(MM);

                    // Store formatted time
                    result.push_back(hour + ":" + minute);
                }
            }
        }

        return result;
    }
};

/*
------------------------------------------------------------
🔹 Example Dry Run:

Input: turnedOn = 1

Valid outputs:
0:01
0:02
0:04
0:08
0:16
0:32
1:00
2:00
4:00
8:00

------------------------------------------------------------
🔹 Key Learning:

✔ Bit manipulation using __builtin_popcount
✔ Brute force over small fixed search space
✔ Proper time formatting
✔ Simulation problems strategy

============================================================
*/

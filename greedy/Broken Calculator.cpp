/*
------------------------------------------------------------
LeetCode Problem: Broken Calculator
Link: https://leetcode.com/problems/broken-calculator/
------------------------------------------------------------

PROBLEM OVERVIEW:
-----------------
You are given two integers:
- startValue
- target

Allowed operations on startValue:
1) Multiply by 2
2) Subtract 1

Goal:
Find the minimum number of operations required to reach
target from startValue.

------------------------------------------------------------

KEY IDEA (Reverse Greedy Thinking):
----------------------------------
Instead of moving from startValue → target,
we work backwards from target → startValue.

Reason:
- Forward direction has too many choices.
- Backward direction gives a single optimal choice at each step.

------------------------------------------------------------

REVERSE OPERATIONS LOGIC:
------------------------
If target is EVEN:
    → The previous value must have been target / 2
    → (Reverse of multiply by 2)

If target is ODD:
    → The previous value must have been target + 1
    → (Reverse of subtract 1)

------------------------------------------------------------

PSEUDO CODE:
------------
operations = 0

WHILE target > startValue:
    IF target is even:
        target = target / 2
    ELSE:
        target = target + 1
    operations++

RETURN operations + (startValue - target)

------------------------------------------------------------

WHY THIS WORKS:
---------------
- Every step reduces target optimally.
- Even numbers shrink fast by division.
- Odd numbers are made even in one step.
- Once target <= startValue, only subtraction is needed.

------------------------------------------------------------

COMPLEXITY:
-----------
Time Complexity  : O(log target)
Space Complexity : O(1)  (iterative logic)

------------------------------------------------------------
NOTE:
-----
This file intentionally contains only:
- Problem understanding
- Algorithm explanation
- Pseudo code

(No actual implementation, for learning & revision purpose)
------------------------------------------------------------
*/

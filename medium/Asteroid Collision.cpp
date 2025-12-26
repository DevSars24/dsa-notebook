/*
===============================================================================
Problem: Asteroid Collision
Platform: GeeksforGeeks
Link:
https://www.geeksforgeeks.org/problems/asteroid-collision/1

Difficulty: Medium
Topic: Stack
===============================================================================

PROBLEM STATEMENT:
------------------
Given an array of integers representing asteroids:
- Positive value  -> moving right
- Negative value  -> moving left

When two asteroids collide:
1. Smaller one explodes
2. If both are equal size, both explode
3. Asteroids moving in the same direction never collide

Return the final state of asteroids after all collisions.

===============================================================================

INTUITION:
----------
Collision can only happen when:
    stack_top > 0  AND  current < 0

A single asteroid can collide with multiple previous asteroids
→ hence a WHILE loop is mandatory.

We use a stack to store indices of asteroids that are still alive.

===============================================================================

WHY `alive` FLAG IS REQUIRED:
-----------------------------
While resolving collisions, the current asteroid may get destroyed.

Cases where current asteroid is destroyed:
1. Previous asteroid is larger
2. Both asteroids are of equal size

In these cases, we MUST NOT push the current asteroid into the stack.

The `alive` flag tracks whether the current asteroid survives
after all collision checks.

===============================================================================

ALGORITHM:
----------
1. Traverse asteroids one by one
2. Assume current asteroid is alive
3. While collision is possible:
   - Compare absolute sizes
   - Pop smaller asteroid
   - Destroy both if equal
4. Push current asteroid ONLY if it is alive
5. Build result from stack

===============================================================================

TIME COMPLEXITY:
----------------
O(N)  (Each asteroid is pushed and popped at most once)

SPACE COMPLEXITY:
-----------------
O(N)  (Stack usage)

===============================================================================
*/

class Solution {
public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {

        stack<int> s1, s2;
        vector<int> result;

        for(int i = 0; i < N; i++) {

            int alive = 1;   // assume current asteroid survives

            // collision condition
            while(!s1.empty() && asteroids[s1.top()] > 0 && asteroids[i] < 0) {

                if(abs(asteroids[s1.top()]) < abs(asteroids[i])) {
                    // previous asteroid destroyed
                    s1.pop();
                }
                else if(abs(asteroids[s1.top()]) == abs(asteroids[i])) {
                    // both destroyed
                    s1.pop();
                    alive = 0;
                    break;
                }
                else {
                    // current asteroid destroyed
                    alive = 0;
                    break;
                }
            }

            // push only if current asteroid survived
            if(alive)
                s1.push(i);
        }

        // reverse stack to maintain original order
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // build result
        while(!s2.empty()) {
            result.push_back(asteroids[s2.top()]);
            s2.pop();
        }

        return result;
    }
};

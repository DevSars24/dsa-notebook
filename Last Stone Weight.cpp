/***************************************************************
 *  Problem Name : Last Stone Weight
 *  Platform     : LeetCode
 *  Problem Link : https://leetcode.com/problems/last-stone-weight/
 *
 *  Intuition:
 *  ------------------------------------------------------------
 *  - Har step me 2 sabse heavy stones uthani hoti hain
 *  - Isliye hume "maximum element repeatedly" chahiye
 *  - priority_queue<int> (Max Heap) best data structure hai
 *
 *  Approach:
 *  ------------------------------------------------------------
 *  1. Saare stones ko max heap me daal do
 *  2. Jab tak heap ka size > 1:
 *       - top() = heaviest stone (x)
 *       - next top() = second heaviest (y)
 *       - agar x != y → (x - y) wapas heap me push
 *  3. Agar heap empty → answer 0
 *     else → heap.top()
 *
 *  Time Complexity:
 *  ------------------------------------------------------------
 *  O(n log n)
 *
 *  Space Complexity:
 *  ------------------------------------------------------------
 *  O(n)
 ***************************************************************/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        // Max Heap
        priority_queue<int> maxHeap;

        // Step 1: Insert all stones
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        // Step 2: Smash stones
        while (maxHeap.size() > 1) {
            int x = maxHeap.top(); // heaviest
            maxHeap.pop();

            int y = maxHeap.top(); // second heaviest
            maxHeap.pop();

            if (x != y) {
                maxHeap.push(x - y);
            }
        }

        // Step 3: Return result
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};

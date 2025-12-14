/*
------------------------------------------------------------
LeetCode 2058
Find the Minimum and Maximum Number of Nodes Between Critical Points
------------------------------------------------------------

PROBLEM STATEMENT:
A critical point in a linked list is defined as either:
1) Local maxima:
   curr->val > prev->val AND curr->val > next->val
2) Local minima:
   curr->val < prev->val AND curr->val < next->val

A node can be a critical point only if it has both
a previous and a next node.

We need to return:
[minDistance, maxDistance]
- minDistance: minimum distance between any two critical points
- maxDistance: maximum distance between any two critical points

If fewer than two critical points exist, return [-1, -1].

------------------------------------------------------------
APPROACH:
------------------------------------------------------------
1. Traverse the linked list using three pointers:
   - prev
   - curr
   - next

2. Since linked lists do NOT have indices, maintain an
   integer counter `index` during traversal to simulate position.

3. When a critical point is found:
   - Store the index of the first critical point
   - Track the previous critical point index
   - Update:
     - minDistance using consecutive critical points
     - maxDistance using first and current critical point

4. If fewer than two critical points are found,
   return {-1, -1}.

------------------------------------------------------------
TIME & SPACE COMPLEXITY:
------------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)

------------------------------------------------------------
*/

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        // Less than 3 nodes => no critical points possible
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        int index = 1;          // curr is at index 1
        int firstIndex = -1;    // first critical point index
        int prevIndex = -1;     // previous critical point index

        int minDist = INT_MAX;
        int maxDist = 0;

        while (next != nullptr) {

            bool isCritical =
                (prev->val > curr->val && curr->val < next->val) ||
                (prev->val < curr->val && curr->val > next->val);

            if (isCritical) {
                if (firstIndex == -1) {
                    firstIndex = index;
                } else {
                    minDist = min(minDist, index - prevIndex);
                    maxDist = index - firstIndex;
                }
                prevIndex = index;
            }

            // Move pointers forward
            prev = curr;
            curr = next;
            next = next->next;
            index++;
        }

        if (minDist == INT_MAX)
            return {-1, -1};

        return {minDist, maxDist};
    }
};

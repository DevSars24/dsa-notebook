# /*

Problem: Remove Zero Sum Consecutive Nodes from Linked List
Link   : [https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/]
Level  : Medium
Topic  : Linked List + Prefix Sum + HashMap
===========================================

PROBLEM STATEMENT (Short):
Given the head of a linked list, remove all consecutive sequences of nodes
that sum to 0, and return the modified linked list.

Example:
Input : 1 -> 2 -> -3 -> 3 -> 1
Output: 3 -> 1

===============================================================================
INTUITION (Big Picture):

The key observation is:
If two prefix sums are equal, then the nodes between them sum to ZERO.

So our task reduces to:

* Track prefix sums while traversing the list
* If a prefix sum repeats, delete the nodes in between

We use:

* Dummy node (to safely delete from head)
* Prefix sum
* HashMap <prefixSum, node>

===============================================================================
BREAK STORY (Why this works?):

Imagine walking along the linked list and carrying a bag (prefix sum).
If at some point, your bag weight becomes the same as before,
then everything you picked in between must cancel out to ZERO.
So you can safely throw those nodes away.

===============================================================================
STEP-BY-STEP INTUITION

## STEP 1: Create a dummy node

Why?

* If the zero-sum sequence starts from head, deleting becomes easy
* Dummy acts as a safe previous node

## STEP 2: Initialize prefix sum & hashmap

Why?

* prefixSum keeps cumulative sum
* hashmap stores where a prefixSum last occurred

## STEP 3: Traverse the linked list

For each node:

* Add its value to prefixSum

## STEP 4: Check if prefixSum already exists

If YES:

* Nodes between previous occurrence and current node sum to ZERO
* We must delete them

## STEP 5: Clean intermediate prefix sums

Why important?

* Those prefix sums are no longer valid after deletion
* If not erased, future links will break

## STEP 6: Relink nodes

Skip the zero-sum nodes by adjusting next pointers

## STEP 7: Return dummy->next

Final cleaned linked list

===============================================================================
CODE IMPLEMENTATION
===================

*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
ListNode* removeZeroSumSublists(ListNode* head) {

```
    unordered_map<int, ListNode*> mp;   // prefixSum -> node
    int prefixsum = 0;

    // Dummy node
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    mp[0] = dummy;

    while (head != nullptr) {
        prefixsum += head->val;

        // If prefix sum already exists
        if (mp.find(prefixsum) != mp.end()) {

            ListNode* start = mp[prefixsum];
            ListNode* temp = start->next;
            int sum = prefixsum;

            // Remove intermediate prefix sums
            while (temp != head) {
                sum += temp->val;
                mp.erase(sum);
                temp = temp->next;
            }

            // Skip zero-sum sublist
            start->next = head->next;
        }
        else {
            mp[prefixsum] = head;
        }

        head = head->next;
    }

    return dummy->next;
}
```

};

# /*

## TIME & SPACE COMPLEXITY

Time Complexity : O(n)
Space Complexity: O(n)

===============================================================================
INTERVIEW ONE-LINER
-------------------

We use prefix sums with a hashmap. Whenever a prefix sum repeats,
all nodes between those two points sum to zero and are removed.
Intermediate prefix sums are erased to maintain correctness.
============================================================

*/

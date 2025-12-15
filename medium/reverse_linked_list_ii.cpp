/************************************************************
 *  Question:
 *  Reverse Linked List II
 *  Link:
 *  https://leetcode.com/problems/reverse-linked-list-ii/
 *
 *  Problem Statement:
 *  Given the head of a singly linked list and two integers
 *  left and right where left <= right, reverse the nodes
 *  of the list from position left to position right, and
 *  return the modified list.
 *
 *  Positions are 1-based.
 *
 *  Example:
 *  Input:  1 -> 2 -> 3 -> 4 -> 5, left = 2, right = 4
 *  Output: 1 -> 4 -> 3 -> 2 -> 5
 *
 ************************************************************/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/************************************************************
 *  INTUITION:
 *
 *  - We do NOT need to reverse the whole list
 *  - Only the sublist from position [left ... right]
 *
 *  Trick:
 *  👉 Use a DUMMY NODE so that even when left == 1
 *     (head changes), the logic remains same.
 *
 *  Technique used:
 *  👉 Head Insertion Technique
 *
 *  We keep inserting the next node of the sublist
 *  at the front of the sublist.
 *
 ************************************************************/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // Edge cases:
        // empty list OR no reversal needed
        if (!head || left == right)
            return head;

        /********************************************************
         * Step 1: Create a dummy node
         * Dummy helps handle cases where left == 1
         ********************************************************/
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        /********************************************************
         * Step 2: Move `prev` to (left - 1)th node
         * prev will point to node just BEFORE the sublist
         ********************************************************/
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        /********************************************************
         * Step 3: Reverse the sublist using head-insertion
         *
         * curr will point to the first node of sublist
         ********************************************************/
        ListNode* curr = prev->next;

        for (int i = 0; i < right - left; i++) {
            ListNode* nxt = curr->next;     // node to be moved
            curr->next = nxt->next;         // detach nxt
            nxt->next = prev->next;         // move nxt to front
            prev->next = nxt;               // update prev
        }

        /********************************************************
         * Step 4: Return new head
         ********************************************************/
        return dummy->next;
    }
};

/************************************************************
 *  DRY RUN (Example):
 *
 *  Input:
 *  1 -> 2 -> 3 -> 4 -> 5
 *  left = 2, right = 4
 *
 *  Dummy:
 *  0 -> 1 -> 2 -> 3 -> 4 -> 5
 *
 *  After iteration 1:
 *  0 -> 1 -> 3 -> 2 -> 4 -> 5
 *
 *  After iteration 2:
 *  0 -> 1 -> 4 -> 3 -> 2 -> 5
 *
 *  Output:
 *  1 -> 4 -> 3 -> 2 -> 5
 *
 ************************************************************/

/************************************************************
 *  TIME & SPACE COMPLEXITY:
 *
 *  Time Complexity:  O(N)
 *  Space Complexity: O(1)
 *
 ************************************************************/

/* ---------- OPTIONAL: Local Testing ---------- */
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Build list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    head = sol.reverseBetween(head, 2, 4);

    // Expected output: 1 4 3 2 5
    printList(head);

    return 0;
}

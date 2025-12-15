/*******************************************************
 * Problem: Reorder List
 * Link: https://leetcode.com/problems/reorder-list/
 *
 * -----------------------------------------------------
 * Question:
 * Given the head of a singly linked list, reorder the list
 * in the following pattern:
 *
 * L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...
 *
 * The reordering must be done IN-PLACE.
 * No modification of node values is allowed.
 *
 * -----------------------------------------------------
 * Example:
 * Input:  1 → 2 → 3 → 4 → 5
 * Output: 1 → 5 → 2 → 4 → 3
 *
 * -----------------------------------------------------
 * Approach Used:
 *
 * Step 1: Find the middle of the linked list
 *         - Used slow and fast pointer technique
 *         - slow moves 1 step, fast moves 2 steps
 *         - When fast reaches end, slow is at middle
 *
 * Step 2: Reverse the second half of the list
 *         - Reverse is required because we need to
 *           take nodes from the END of the list
 *         - Since it's a singly linked list, we cannot
 *           move backward directly
 *         - So we reverse the second half using
 *           3-pointer approach (prev, curr, next)
 *
 * Step 3: Merge both halves alternately
 *         - First half starts from head
 *         - Second half starts from reversed list
 *         - Merge nodes one by one
 *
 * -----------------------------------------------------
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *******************************************************/

class Solution {
public:

    /***************************************************
     * Reverse Linked List using 3-pointer approach
     *
     * prev -> curr -> next
     *
     * This helps us move from the end of the list,
     * which is required in reorder list problem.
     ***************************************************/
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;  // save next node
            curr->next = prev;            // reverse link
            prev = curr;                  // move prev
            curr = next;                  // move curr
        }

        return prev;   // new head of reversed list
    }

    /***************************************************
     * Main Function: reorderList
     ***************************************************/
    void reorderList(ListNode* head) {

        // Edge case: empty list or single node
        if (!head || !head->next) return;

        // Step 1: Find middle using slow & fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half of the list
        ListNode* second = reverseList(slow->next);

        // Cut the first half
        slow->next = nullptr;

        // Step 3: Merge both halves
        ListNode* first = head;

        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};

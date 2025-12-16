class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;          // ✅ connect dummy to head

        ListNode* prev = dummy;
        ListNode* curr = head;       // ✅ start from head

        while (curr != nullptr) {

            if (curr->val == val) {
                prev->next = curr->next;   // delete curr
                curr = curr->next;
            } else {
                prev = curr;              // move prev only when not deleted
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};

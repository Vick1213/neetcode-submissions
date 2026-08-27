class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);   // real node, dummy.next = head
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // advance fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // move both until fast reaches the last node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow is now right before the node to remove
        ListNode* toDelete = slow->next;
        slow->next = toDelete->next;
        delete toDelete;

        return dummy.next;
    }
};
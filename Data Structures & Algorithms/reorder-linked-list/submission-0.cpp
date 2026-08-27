class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        // 1. Find the length of the list
        int length = 1;
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
            length++;
        }

        // 2. Walk to the last node of the first half, then cut the list in two
        int mid = length / 2;
        ListNode* firstTail = head;
        for (int i = 0; i < mid - 1; i++) {
            firstTail = firstTail->next;
        }
        ListNode* secondHead = firstTail->next;
        firstTail->next = nullptr;  // sever the two halves

        // 3. Reverse the second half
        secondHead = reverseList(secondHead);

        // 4. Zipper-merge the two halves
        ListNode* first = head;
        ListNode* second = secondHead;
        while (first != nullptr && second != nullptr) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            if (firstNext != nullptr) {
                second->next = firstNext;
            }

            first = firstNext;
            second = secondNext;
        }
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;

        ListNode* resHead = new ListNode();
        ListNode* ittrhead = resHead;
        ListNode* prev = resHead;   // NEW: last node that holds a real computed digit

        while(l1 && l2)
        {
            int y = 0;
            if(carry) y = l1->val + l2->val + 1;
            else y = l1->val + l2->val;

            if(y >= 10) { carry = true; y = y % 10; }
            else carry = false;

            ittrhead->val = y;
            prev = ittrhead;              // NEW: this node is now "claimed"
            ittrhead->next = new ListNode();
            ittrhead = ittrhead->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1)
        {
            if(!carry)
            {
                prev->next = l1;          // NEW: discard the unused placeholder
            }
            else
            {
                while(l1 != nullptr && carry)
                {
                    int x = l1->val + 1;
                    if(x >= 10) { x = x % 10; carry = true; }
                    else { carry = false; }

                    ittrhead->val = x;
                    l1 = l1->next;

                    if(l1 != nullptr && carry)
                    {
                        ittrhead->next = new ListNode();
                        ittrhead = ittrhead->next;
                    }
                }
                if(carry) ittrhead->next = new ListNode(1);
                else if(l1 != nullptr) ittrhead->next = l1;
            }
        }
        else if(l2)
        {
            if(!carry)
            {
                prev->next = l2;          // NEW: discard the unused placeholder
            }
            else
            {
                while(l2 != nullptr && carry)
                {
                    int x = l2->val + 1;
                    if(x >= 10) { x = x % 10; carry = true; }
                    else { carry = false; }

                    ittrhead->val = x;
                    l2 = l2->next;

                    if(l2 != nullptr && carry)
                    {
                        ittrhead->next = new ListNode();
                        ittrhead = ittrhead->next;
                    }
                }
                if(carry) ittrhead->next = new ListNode(1);
                else if(l2 != nullptr) ittrhead->next = l2;
            }
        }
        else if(carry)
        {
            ittrhead->val = 1;   // placeholder's ->next is already nullptr, no extra node needed
        }
        else
        {
            prev->next = nullptr;   // NEW: equal-length lists, no final carry — discard placeholder
        }

        return resHead;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {

        if(head ==nullptr) return false;
        ListNode* first = head;
        ListNode* second = head->next;


        while(first!= second || second!=nullptr || first!=nullptr)
        {

             if(first->next == nullptr)
            return false;
            if(second->next== nullptr)
            {return false;}
            if(second->next->next== nullptr)
            {return false;}
            first = first->next;
            second = second->next->next;

            if(first == second)
            {return true;}

           
        }

        return false;
    }
};

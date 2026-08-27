class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        Node* newhead = new Node(head->val);
        unordered_map<Node*,Node*> addrmap;

        Node* temphead = head;
        Node* copyhead= newhead;
        while(temphead->next!=nullptr)
        {   
            Node* newcopy = new Node(temphead->next->val);
            copyhead->next = newcopy;
            addrmap[temphead] = copyhead;
            copyhead =copyhead->next;
            temphead = temphead->next;
            
        }
        addrmap[temphead] = copyhead;  // map the last node too — loop above stops one short

        // to figure out random now, we have mappings of old and new, if node 1 points to node 8 we make newnode1 point to newnode8 
        Node* randomhead = head;
        Node* newrandomhead = newhead;

        while(randomhead!=nullptr)
        {
            newrandomhead->random = addrmap[randomhead->random];
            randomhead = randomhead->next;
            newrandomhead = newrandomhead->next;
        }

        return newhead;
        
    }
};
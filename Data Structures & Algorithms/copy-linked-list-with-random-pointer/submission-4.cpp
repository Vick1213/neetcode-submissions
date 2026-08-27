class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> addrmap;

        // Pass 1: create every copy node, map original -> copy
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            addrmap[curr] = new Node(curr->val);
        }

        // Pass 2: wire up next and random using the map
        // addrmap[nullptr] default-constructs to nullptr, which handles
        // the "no random pointer" / "end of list" cases for free.
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            addrmap[curr]->next = addrmap[curr->next];
            addrmap[curr]->random = addrmap[curr->random];
        }

        return addrmap[head];
    }
};
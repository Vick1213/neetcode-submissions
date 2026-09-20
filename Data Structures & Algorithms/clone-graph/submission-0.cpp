class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> oldToNew;
        queue<Node*> myQueue;

        oldToNew[node] = new Node(node->val);
        myQueue.push(node);

        while (!myQueue.empty()) {
            Node* curr = myQueue.front();
            myQueue.pop();

            for (auto& neighbor : curr->neighbors) {
                if (!oldToNew.contains(neighbor)) {
                    oldToNew[neighbor] = new Node(neighbor->val);
                    myQueue.push(neighbor);
                }
                oldToNew[curr]->neighbors.push_back(oldToNew[neighbor]);
            }
        }

        return oldToNew[node];
    }
};
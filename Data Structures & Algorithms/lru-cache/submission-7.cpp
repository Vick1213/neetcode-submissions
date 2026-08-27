
class ListNode
{
 public:
  int key;
 int value;
  ListNode* next;
 ListNode*prev;
 ListNode()
 {
    this->key =0;
    this->value =0;
     prev = nullptr;
     next = nullptr;
 }
 ListNode(int key, int value)
 {
     this->key = key;
     this->value =  value;
     prev = nullptr;
     next = nullptr;
 }



};


class LRUCache {
public:
  unordered_map<int,ListNode*> hashmap;
  ListNode* mru ;
  ListNode* lru ;
    LRUCache(int capacity) {
        
        this->capacity = capacity;
        
        lru = new ListNode();
        mru = new ListNode();
        lru->next = mru;
        mru->prev = lru;
    }
    
    int get(int key) {
    if (!hashmap.contains(key)) return -1;
    ListNode* change = hashmap[key];

    change->prev->next = change->next;   // unlink from old spot
    change->next->prev = change->prev;

    ListNode* last = mru->prev;          // relink at MRU end
    last->next = change;
    change->prev = last;
    change->next = mru;
    mru->prev = change;

    return change->value;
}
    
   void put(int key, int value) {
    // key already exists — update value and move to MRU, no eviction
    if (hashmap.contains(key)) {
        ListNode* node = hashmap[key];
        node->value = value;

        node->prev->next = node->next;   // unlink from current spot
        node->next->prev = node->prev;

        ListNode* last = mru->prev;      // relink at MRU end
        last->next = node;
        node->prev = last;
        node->next = mru;
        mru->prev = node;
        return;
    }

    if (hashmap.size() == this->capacity) {
        // cache full — evict LRU, then insert the new node
        ListNode* newnode = new ListNode(key, value);

        ListNode* toDelete = lru->next;
        lru->next = toDelete->next;
        toDelete->next->prev = lru;
        hashmap.erase(toDelete->key);
        toDelete->next = nullptr;
        toDelete->prev = nullptr;
        delete toDelete;

        hashmap[key] = newnode;
        ListNode* last = mru->prev;
        last->next = newnode;
        newnode->prev = last;
        newnode->next = mru;
        mru->prev = newnode;
    } else {
        // room available — plain insert at MRU end
        ListNode* newnode = new ListNode(key, value);
        hashmap[key] = newnode;
        ListNode* last = mru->prev;
        last->next = newnode;
        newnode->prev = last;
        newnode->next = mru;
        mru->prev = newnode;
    }
}
private:
int capacity;

};

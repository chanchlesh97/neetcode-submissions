class CacheNode {
    public:
        int key;
        int val;
        CacheNode * prev;
        CacheNode * next;
        CacheNode(int key, int val) {
            this->key = key;
            this-> val = val;
            this->prev = nullptr;
            this->next = nullptr;
        }
};

class LRUCache {
    CacheNode * front = nullptr, * trail = nullptr;
    int c, size;
    unordered_map<int,CacheNode*> keyMap;
public:
    LRUCache(int capacity) {
        this->c = capacity;
        size = 0;
        front = new CacheNode(0,0);
        trail = new CacheNode(0,0);
        front->next = trail;
        trail ->prev = front;

    }

    void insert(CacheNode *node) {
        node ->next = front->next;
        node ->prev = front;
        node->next->prev = node;
        front ->next = node;
        
    }
    
    int get(int key) {
        CacheNode * t = nullptr, *temp;
        if(keyMap.count(key)) {
            t = keyMap[key];
            t->prev->next = t->next;
            t->next->prev = t->prev;

            t->next = t->prev = nullptr;
            insert(t);
            return t->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        CacheNode * t = nullptr, *temp;
        if(keyMap.count(key)) {
            t = keyMap[key];
            t->val = value;
            t->prev->next = t->next;
            t->next->prev = t->prev;
            t->next = t->prev = nullptr;
        }else {
            t = new CacheNode(key, value);
            // t = &cn;
            if(size == c) {
                keyMap.erase(trail->prev ->key);
                trail->prev = trail ->prev->prev;
                trail->prev ->next = trail;

            } else {
                size++;
            }
            keyMap[key] = t;
        }

        insert(t);

        
    }
};

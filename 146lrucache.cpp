class LRUCache {
public:
    LRUCache(int capacity) {
         cap = capacity;
         seq = 0;        
    }

    struct cache {
        int key;
        int value ;
        uint64_t seq;
    };

    struct cacheCompare {
        bool operator() (const cache& lhs, const cache& rhs) const {
            return lhs.seq < rhs.seq;
        }
    };
    
    int get(int key) {
        if (cacheMp.find(key) ==cacheMp.end()) {
            return -1;
        }

        cache cc = cacheMp[key];
        cacheSt.erase(cc);
        cc.seq = seq ++;
        forceput(cc);

        return cc.value;
    }

    void forceput(cache& cc) {
            cacheMp[cc.key] = cc;
            cacheSt.insert(cc);
    }
    
    void put(int key, int value) {
        cache cc;
        if (cacheMp.find(key) != cacheMp.end()) {
            cacheSt.erase(cacheMp[key]);

            cc.value = value;
            cc.seq = seq++;
            cc.key = key;
            forceput(cc);
            return ;
        }

        if (cacheMp.size() >= cap) {
            cache c = *cacheSt.begin();
            cacheSt.erase(c);
            cacheMp.erase(c.key);
        }

        cc.value = value;
        cc.key = key;
        cc.seq = seq++;
        forceput(cc);
    }

    
    map<int, cache> cacheMp;
    set<cache, cacheCompare> cacheSt; 
    int cap;
    uint64_t seq;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
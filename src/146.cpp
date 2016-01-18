class LRUCache{
private:
    struct CacheNode {
        int key;
        int value;
        CacheNode(int k, int v): key(k), value(v) {}
    };
    int capacity;
    list<CacheNode> clist;
    unordered_map<int, list<CacheNode>::iterator> cmap;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        if (cmap.find(key) == cmap.end())
            return -1;
        clist.splice(clist.begin(), clist, cmap[key]);
        return clist.begin()->value;
    }
    void set(int key, int value) {
        if (cmap.find(key) != cmap.end()) {
            clist.splice(clist.begin(), clist, cmap[key]);
            clist.begin()->value = value;
            cmap[key] = clist.begin();
        }
        else {
            if (cmap.size() < capacity) {
                clist.push_front(CacheNode(key, value));
                cmap[key] = clist.begin();
            }
            else {
                cmap.erase(clist.back().key);
                clist.pop_back();
                clist.push_front(CacheNode(key, value));
                cmap[key] = clist.begin();
            }
        }
    }
};
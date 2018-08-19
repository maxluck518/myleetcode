typedef struct node{
    int key;
    int value;
    node * next;
    node * pre;
    node(int x,int y) : key(x),value(y),next(NULL),pre(NULL) {}
}node;
class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        node *tmp1 = new node(0,0);
        node *tmp2 = new node(0,0);
        head = tmp1;
        tail = tmp2;
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end()) return -1;
        node * res = it->second;
        node * pre_node = res->pre;
        node * next_node = res->next;

        pre_node->next = next_node;
        next_node->pre = pre_node;

        pre_node = tail->pre;
        next_node = tail;
        res->next = next_node;
        res->pre = pre_node;
        pre_node->next = res;
        next_node->pre = res;
        return res->value;
    }
    
    void put(int key, int value) {
        auto itt = mp.find(key);
        if(itt != mp.end() && mp.size() != 0){
            node * tmp = itt->second;
            node * pre_node = tmp->pre;
            node * next_node = tmp->next;
            pre_node->next = next_node;
            next_node->pre = pre_node;
            mp.erase(itt->first);
            delete tmp;
        }
        if(mp.size() == capacity) {
            node *tmp = head->next;
            auto it = mp.find(tmp->key);
            mp.erase(it->first);
            node * pre_node = head;
            node * next_node = tmp->next;
            pre_node->next = next_node;
            next_node->pre = pre_node;
            delete tmp;
        }
        node *tmp = new node(key,value);
        node * pre_node = tail->pre;
        node * next_node = tail;

        tmp->next = next_node;
        tmp->pre = pre_node;
        next_node->pre = tmp;
        pre_node->next = tmp;

        mp.insert(make_pair(key,tmp));
        // node * test = head->next;
        // while(test != tail){
            // cout << test->key << endl;
        // }
        // cout << "hdfhsadf" << endl;
    }
private:
    int capacity;
    map<int,node*> mp;
    node *head;
    node *tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */


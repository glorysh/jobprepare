#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    struct LN {
        int key;
        LN *l, *r;
        LN(int key = 0) : key(key), l(nullptr), r(nullptr) {} 
    };

    int cap;
    LN *head, *tail;
    unordered_map<int, int> mp1;    // key->val
    unordered_map<int, LN*> mp2;    // key->ptr

    void link(LN *a, LN *b) {
        a->r = b;
        b->l = a;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head = new LN();
        tail = new LN();
        link(head, tail);
    }

    int get(int key) {
        if (!mp1.count(key)) {
            return -1;
        }
        int val = mp1[key];
        LN *ptr = mp2[key];
        link(ptr->l, ptr->r);
        link(tail->l, ptr);
        link(ptr, tail);
        return val;
    }

    void put(int key, int val) {
        if (cap == 0) return;
        if (get(key) != -1) {
            mp1[key] = val;
            return;
        }
        int sz = mp1.size();
        if (sz == cap) {
            LN *ptr = head->r;
            link(ptr->l, ptr->r);
            mp1.erase(ptr->key);
            mp2.erase(ptr->key);
            delete ptr;
        }
        LN* node = new LN(key);
        link(tail->l, node);
        link(node, tail);
        mp1.insert({key, val});
        mp2.insert({key, node});
        return;
    }
};


int main() {
    LRUCache t = LRUCache(2);
    t.put(1, 1);
    t.put(2, 2);
    cout << t.get(1) << endl;
    t.put(3, 3);
    cout << t.get(2) << endl;
    t.put(4, 4);
    cout << t.get(1) << endl;
    cout << t.get(3) << endl;
    cout << t.get(4) << endl;
    return 0;
}
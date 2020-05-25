/*
146. LRU缓存机制

运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
*/
#include<list>
#include<unordered_map>
#include<vector>
using namespace std;
class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator> m;
    list<pair<int,int>> l;
    int curCap = 0;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it!=m.end()) {
            int val = it->second->second;
            l.erase(it->second);
            l.push_front(make_pair(key,val));
            m[key] = l.begin();
            return val;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it!=m.end()) {
            l.erase(it->second);
        }
        l.push_front(make_pair(key,value));
        m[key] = l.begin();
        if(l.size()>cap) {
            int finalKey = l.back().first;
            m.erase(finalKey);
            l.pop_back();
        }
    }
};
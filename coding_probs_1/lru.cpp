// https://www.jointaro.com/interviews/questions/lru-cache/?company=grab

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class LRU{
    private:
    size_t m_capacity;
    using ListIterator = list<pair<int,int>>::iterator;
    unordered_map<int,ListIterator> cache;
    list<pair<int,int>> items;

    public:
    LRU(int capacity):m_capacity(capacity){}

    int getKey(int key){
        auto it = cache.find(key);
        if(it == cache.end()) return -1;
        items.splice(items.begin(),items,it->second);
        return it->second->second;
    }

    void put(int key, int value){
        auto it = cache.find(key);
        if(it != cache.end()){
            it->second->second = value;
            items.splice(items.begin(), items, it->second);
            return;
        }
        if(items.size() == m_capacity){
            int key_to_delete = items.back().first;
            items.pop_back();
            cache.erase(key_to_delete);
        }
        items.emplace_front(key,value);
        cache[key] = items.begin();
    }
};
#include <iostream>
#include <list>

class LRUCache {
	private:
	using ListIterator = std::list<std::pair<int, int>>::iterator;

	size_t m_capacity;
	std::list<std::pair<int, int>> items;
	std::unordered_map<int, ListIterator> cache;

	public:
	LRUCache(int cap) : m_capacity(cap) {}

	int get(int key){
		auto it = cache.find(key);
		if (it == cache.end()) return -1;
		items.splice(items.begin(), items, it->second);
		return it->second->second;
	}

	void put(int key, int value) {

	auto it = cache.find(key);

	if(it != cache.end()) {
		items.splice(items.begin(), items, it->second);
		it->second->second = value;
		return;
	}
	if(items.size() == m_capacity) {
		int key_delete = items.back().first;
		items.pop_back();
		cache.erase(key_delete);
	}
	items.emplace_front(key, value);
	cache[key] = items.begin();
	}
};

int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    std::cout << lru.get(1) << std::endl; // returns 1
    lru.put(3, 3); // evicts key 2
    std::cout << lru.get(2) << std::endl; // returns -1 (not found)
    lru.put(4, 4); // evicts key 1
    std::cout << lru.get(1) << std::endl; // returns -1 (not found)
    std::cout << lru.get(3) << std::endl; // returns 3
    std::cout << lru.get(4) << std::endl; // returns 4
    return 0;
}
#include <iostream>
#include <list>
#include <unordered_map>

class LFUCache {
	private:
	struct Node {
		int key;
		int value;
		int freq;
	};
	using ListIterator = std::list<Node>::iterator;

	size_t m_capacity;
	int m_minFreq;
	std::unordered_map<int, std::list<Node>> freqList;
	std::unordered_map<int, ListIterator> cache;

	void touch(ListIterator it) {
		int key = it->key;
		int value = it->value;
		int freq = it->freq;

		freqList[freq].erase(it);
		if (freqList[freq].empty()) {
			freqList.erase(freq);
			if (m_minFreq == freq) m_minFreq++;
		}

		freqList[freq + 1].push_front(Node{key, value, freq + 1});
		cache[key] = freqList[freq + 1].begin();
	}

	public:
	LFUCache(int cap) : m_capacity(cap), m_minFreq(0) {}

	int get(int key) {
		auto it = cache.find(key);
		if (it == cache.end()) return -1;
		int value = it->second->value;
		touch(it->second);
		return value;
	}

	void put(int key, int value) {
		if (m_capacity == 0) return;

		auto it = cache.find(key);
		if (it != cache.end()) {
			it->second->value = value;
			touch(it->second);
			return;
		}

		if (cache.size() == m_capacity) {
			auto &minList = freqList[m_minFreq];
			int key_delete = minList.back().key;
			minList.pop_back();
			if (minList.empty()) freqList.erase(m_minFreq);
			cache.erase(key_delete);
		}

		freqList[1].push_front(Node{key, value, 1});
		cache[key] = freqList[1].begin();
		m_minFreq = 1;
	}
};

int main() {
    LFUCache lfu(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    std::cout << lfu.get(1) << std::endl; // returns 1
    lfu.put(3, 3); // evicts key 2 (least frequently used)
    std::cout << lfu.get(2) << std::endl; // returns -1 (not found)
    std::cout << lfu.get(3) << std::endl; // returns 3
    lfu.put(4, 4); // evicts key 1 (tie broken by least recently used)
    std::cout << lfu.get(1) << std::endl; // returns -1 (not found)
    std::cout << lfu.get(3) << std::endl; // returns 3
    std::cout << lfu.get(4) << std::endl; // returns 4
    return 0;
}

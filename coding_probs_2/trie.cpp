#include <iostream>
using namespace std;

struct TrieNode {
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        memset(child, 0, sizeof(child));
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* cur = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!cur->child[idx])
                cur->child[idx] = new TrieNode();

            cur = cur->child[idx];
        }

        cur->isEnd = true;
    }

    bool search(string word) {
        TrieNode* cur = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!cur->child[idx])
                return false;

            cur = cur->child[idx];
        }

        return cur->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;

        for (char c : prefix) {
            int idx = c - 'a';

            if (!cur->child[idx])
                return false;

            cur = cur->child[idx];
        }

        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("cat");
    trie.insert("care");
    trie.insert("dog");

    cout << trie.search("care") << endl;
    cout << trie.startsWith("ca") << endl;
}
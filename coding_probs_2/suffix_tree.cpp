#include <iostream>
#include <map>
 
using namespace std;

struct Node {
    map<char, Node*> next;
};

class NaiveSuffixTree {

    Node* root;

public:

    NaiveSuffixTree() {
        root = new Node();
    }

    void build(string s) {

        int n = s.size();

        for(int i=0;i<n;i++){

            Node* cur = root;

            for(int j=i;j<n;j++){

                char c = s[j];

                if(!cur->next.count(c))
                    cur->next[c] = new Node();

                cur = cur->next[c];
            }
        }
    }

    bool contains(string p){

        Node* cur = root;

        for(char c:p){

            if(!cur->next.count(c))
                return false;

            cur = cur->next[c];
        }

        return true;
    }
};

int main(){

    NaiveSuffixTree tree;

    tree.build("banana");

    cout << tree.contains("ana") << endl;
    cout << tree.contains("apple") << endl;
}
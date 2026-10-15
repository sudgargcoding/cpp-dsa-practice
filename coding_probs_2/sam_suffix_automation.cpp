#include <iostream>
#include <map>

using namespace std;

struct State {
    int len;
    int link;
    map<char,int> next;
};

class SuffixAutomaton {

    vector<State> st;
    int last;

public:

    SuffixAutomaton(int maxLen) {
        st.resize(2 * maxLen);

        st[0].len = 0;
        st[0].link = -1;

        last = 0;
        sz = 1;
    }

    int sz;

    void extend(char c) {

        int cur = sz++;
        st[cur].len = st[last].len + 1;

        int p = last;

        while (p != -1 && !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }

        if (p == -1) {
            st[cur].link = 0;
        }
        else {

            int q = st[p].next[c];

            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            }
            else {

                int clone = sz++;

                st[clone] = st[q];
                st[clone].len = st[p].len + 1;

                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }

                st[q].link = clone;
                st[cur].link = clone;
            }
        }

        last = cur;
    }

    void build(string s) {
        for(char c : s)
            extend(c);
    }

    bool contains(string p) {

        int v = 0;

        for(char c : p){

            if(!st[v].next.count(c))
                return false;

            v = st[v].next[c];
        }

        return true;
    }
};

int main(){

    string s = "banana";

    SuffixAutomaton sam(s.size());

    sam.build(s);

    cout << sam.contains("ana") << endl;
    cout << sam.contains("apple") << endl;
}
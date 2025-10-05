#include <iostream>
#include <string>
#include <vector>
#include <map>

struct State {
    int len, link;
    std::map<char, int> next;
};

const int MAXLEN = 200005;
State st[MAXLEN * 2];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[q].len == st[p].len + 1) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int cases;
    std::cin >> cases;

    sa_init();

    for (int i = 0; i < cases; i++) {
        std::string s;
        std::cin >> s;
        
        last = 0; 
        
        for (char c : s) {
            sa_extend(c);
        }
    }

    long long total_unique_substrings = 0;
    for (int i = 1; i < sz; i++) {
        total_unique_substrings += st[i].len - st[st[i].link].len;
    }

    std::cout << total_unique_substrings << "\n";

    return 0;
}
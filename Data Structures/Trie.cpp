#include <bits/stdc++.h>
using namespace std;

void _print() { cerr << "]" << endl; }
template<typename T, typename... V>
void _print(T t, V... v) { cerr << t; if (sizeof...(v)) cerr << ", "; _print(v...); }

#define dbg(x...) cerr << "[" << #x << "]: ["; _print(x)
#define endl '\n'
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define rforn(i, n) for (int i = int(n); i >= 0; --i)
#define form(i, n, m, x) for (int i = int(n); i < int(m); i += int(x))
#define rform(i, n, m, x) for (int i = int(n); i >= int(m); i -= int(x))

struct Trie {
    struct Node {
        char c;
        int cont;
        Node* next[123];

        Node(char _c): c(_c) {}
    };

    Node* root;

    Trie() {
        root = new Node('$');
    }

    void insert(const string &s, int i, Node*& curr) {
        if (sz(s) == i) return;
        if (curr->next[int(s[i])] == NULL) {
            curr->next[int(s[i])] = new Node(s[i]);
        }
        curr->next[int(s[i])]->cont++;
        insert(s, i + 1, curr->next[int(s[i])]);
    }

    void insert(const string &s) {
        insert(s, 0, root);
    }

    pair<int, int> query(const string &s, int i, Node*& curr) {
        if (sz(s) == i || curr->next[int(s[i])] == NULL) return make_pair(i, curr->cont);
        return query(s, i + 1, curr->next[int(s[i])]);
    }

    pair<int, int> query(const string &s) {
        return query(s, 0, root);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    return 0;
}
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

struct Node {
    int cont;
    Node* child[26];
};

struct Trie {
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(const string &s) {
        Node* curr = root;
        for (int i = 0; i < sz(s); ++i) {
            if (curr->child[s[i] - 'a'] == NULL) {
                curr->child[s[i] - 'a'] = new Node();
            }
            curr->child[s[i] - 'a']->cont++;
            curr = curr->child[s[i] - 'a'];
        }
    }

    pair<int, int> query(const string &s) {
        Node* curr = root;
        for (int i = 0; i < sz(s); ++i) {
            if (curr->child[s[i] - 'a'] == NULL) {
                return make_pair(i, curr->cont);
            }
            curr = curr->child[s[i] - 'a'];
        }
        return make_pair(sz(s), curr->cont);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    return 0;
}
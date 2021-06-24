// - Descripción: Halla el tamaño maximo del conjunto de nodos idependientes en un arbol
// - Complejidad: O(V)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

const int MAX = 105;
vector<int> tree[MAX];

pair<int, int> dfs(int v, int p) {
    int a = 0, b = 1;
    for (int &u : tree[v]) {
        if (u == p) continue;
        pair<int, int> r = dfs(u, v);
        a += r.second;
        b += r.first;
    }
    return {a, max(a, b)};
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int v, u; cin >> v >> u;
        v--, u--;
        tree[v].push_back(u);
        tree[u].push_back(v);
    }
    cout << dfs(0, -1).second << endl;   
    return 0;
}

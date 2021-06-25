// - Descripción: Recorrido en anchura
// - Complejidad: O(V + E)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int main() {
    int n, m; cin >> n >> m;
    vector<int> ady[n];

    for (int i = 0; i < m; ++i) {
        int v, u; cin >> v >> u;
        v--, u--;
        ady[v].push_back(u);
        ady[u].push_back(v);
    }

    vector<bool> vis(n);

    auto bfs = [&](int v) {
        queue<int> qu;
        qu.push(v);
        while (sz(qu)) {
            v = qu.front();
            qu.pop();
            vis[v] = true;
            for (int &u : ady[v]) {
                if (!vis[u]) {
                    qu.push(u);
                }
            }            
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) bfs(i);
    }
    return 0;
}

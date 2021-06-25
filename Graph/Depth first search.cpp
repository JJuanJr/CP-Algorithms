// - Descripción: Recorrido en profundidad
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
    function<void(int)> dfs = [&](int v) {
        vis[v] = true;
        for (int &u : ady[v]) {
            if (!vis[u]) dfs(u);
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) dfs(i);
    }
    return 0;
}

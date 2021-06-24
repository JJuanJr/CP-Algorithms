// - Descripción: Detecta si existe un ciclo
// - Complejidad: O(V + E)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int main() {
    int n, m; cin >> n >> m;
    vector<int> ady[n];

    while (m--) {
        int v, u; cin >> v >> u;
        v--, u--;
        ady[v].push_back(u);
    }

    vector<int> vis(n);

    function<bool(int, int)> dfs = [&](int v, int p) {
        vis[v] = 1;
        for (int &u : ady[v]) {
            if (u == p || vis[u] == 2) continue;
            if (vis[v] == 1 || dfs(u, v)) return true;
        }
        vis[v] = 2;
        return false;
    };

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            if (dfs(i, -1)) {
                cout << "YES" << endl;
                break;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}

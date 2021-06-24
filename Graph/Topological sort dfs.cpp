// - Descripción: Encuentra el orden topologico
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
    }

    vector<int> topo;
    vector<bool> vis(n);

    function<void(int)> dfs = [&](int v) {
        vis[v] = true;
        for (int &u : ady[v]) {
            if (!vis[u]) dfs(u);
        }
        topo.push_back(v);
    };

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    for (int &i : topo) cout << i << " ";
    cout << endl;
    return 0;
}

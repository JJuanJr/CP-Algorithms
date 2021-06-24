// - Descripción: Comprueba si un grafo es bipartito
// - Complejidad: O(V + E)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int main() {
    int n, m; cin >> n >> m;
    vector<int> ady[n];

    while (m--) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        ady[v].push_back(u);
        ady[u].push_back(v);
    }

    vector<int> color(n, -1);

    auto bipartite = [&](int v) -> bool {
        queue<int> qu;
        qu.push(v);
        color[v] = 0;
        while (sz(qu)) {
            v = qu.front();
            qu.pop();
            for (int &u : ady[v]) {
                if (color[u] == -1) {
                    color[u] = color[v] ^ 1;
                    qu.push(u);
                } else if (color[u] == color[v]) {
                    return false;
                }
            }
        }
        return true;
    };

    bool ok = true;
    for (int i = 0; i < n && ok; ++i) {
        if (color[i] == -1) {
            ok &= bipartite(i);
        }
    }
    
    if (ok) {
        for (int i = 0; i < n; ++i) {
            cout << i << " -> " << color[i] << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

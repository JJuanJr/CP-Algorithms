// - Descripción: Encuentra el camino minimo entre cualquier par de nodos
// - Complejidad: O(V^3)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int main() {
    int n; cin >> n;
    int ady[n][n];
    const int INF = 1e9;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ady[i][j] = (i == j ? 0 : INF);
        }
    }

    for (int i = 0; i < n; ++i) {
        int v, u, w; cin >> v >> u >> w;
        v--, u--;
        ady[v][u] = ady[u][v] = w;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ady[i][j] = min(ady[i][j], ady[i][k] + ady[k][j]);
            }
        }
    }
    return 0;
}

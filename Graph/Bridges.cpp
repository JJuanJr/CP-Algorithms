// - Descripción: Halla los puentes
// - Complejidad: O(V + E)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int n, m;
vector<vector<int>> ady;
vector<int> tin, low;
vector<pair<int, int>> bridges;
int timer;

void dfs(int v, int p = -1) {
    tin[v] = low[v] = timer++;
    for (int &u : ady[v]) {
        if (p == u) continue;
        if (tin[u] != -1) {
            low[v] = min(low[v], low[u]);
        } else {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] > tin[v]) {
                bridges.emplace_back(v, u);
            }
        }
    }
}


int main() {
    cin >> n >> m;
    ady.resize(n);
    while (m--) {
        int v, u; cin >> v >> u;
        ady[v].push_back(u);
        ady[u].push_back(v);
    }

    timer = 0;
    tin.assign(n, -1);
    low.assign(n, -1);

    for (int i = 0; i < n; ++i) {
        if (tin[i] == -1) {
            dfs(i);
        }
    }    
    return 0;
}

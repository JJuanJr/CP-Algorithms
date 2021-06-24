// - Descripción: Convierte un grafo con ciclos a un DAG
// - Complejidad: 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int main() {
    int n, m; cin >> n >> m;

    vector<int> ady[n], rady[n];
    vector<int> grado(n);

    while (m--) {
        int a, b; cin >> a >> b;
        a--, b--;
        ady[a].push_back(b);
        rady[b].push_back(a);
    }

    vector<int> order;
    vector<bool> vis(n);
    vector<vector<int>> comp;

    function<void(int)> dfs1 = [&](int v) {
        vis[v] = true;
        for (int &u : ady[v]) {
            if (!vis[u]) {
                dfs1(u);
            }
        }
        order.push_back(v);
    };

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs1(i);
        }
    }

    vis.assign(n, false);

    function<void(int)> dfs2 = [&](int v) {
        vis[v] = true;
        comp.back().push_back(v);
        for (int &u : rady[v]) {
            if (!vis[u]) {
                dfs2(u);
            }
        }
    };

    for (int i = n - 1; i >= 0; --i) {
        if (!vis[order[i]]) {
            comp.push_back({});
            dfs2(order[i]);
        }
    }
    vector<int> nady[sz(comp)];
    vector<int> tag(n);

    for (int i = 0; i < sz(comp); ++i) {
        for (int &j : comp[i]) {
            tag[j] = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int &j : ady[i]) {
            if (tag[i] != tag[j]) {
                nady[tag[i]].push_back(tag[j]);
            }
        }
    }

    for (int i = 0; i < sz(comp); ++i) {
        sort(nady[i].begin(), nady[i].end());
        nady[i].resize(unique(nady[i].begin(), nady[i].end()) - nady[i].begin());
        for (int &j : nady[i]) {
            cout << i + 1 << " -> " << j + 1 << endl;
        }
    }
    return 0;
}

// - Descripción: Halla el costo total del arbol recubridor minimo de un grafo no dirigido y conexo
// - Complejidad: O(E * log(V))

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

struct edge {
    int v, w;

    bool operator < (const edge &x) const {
        return w > x.w;
    }
};

int main() {
    int n, m; cin >> n >> m;
    vector<edge> ady[n];
    for (int i = 0; i < m; ++i) {
        int v, u, w; cin >> v >> u >> w;
        v--, u--;
        ady[v].push_back({u, w});
        ady[u].push_back({v, w});
    }

    priority_queue<edge> pq;
    bool vis[n];
    memset(vis, false, sizeof vis);

    vis[0] = true;
    for (edge &i : ady[0]) {
        if (!vis[i.v]) pq.push(i);
    }

    int mst = 0;
    while (sz(pq)) {
        edge v = pq.top();
        pq.pop();

        if (!vis[v.v]) {
            mst += v.w;
            vis[v.v] = true;
            for (edge &i : ady[v.v]) {
                if (!vis[i.v]) {
                    pq.push(i);
                }
            }
        }
    }
    cout << mst << endl;
    return 0;
}

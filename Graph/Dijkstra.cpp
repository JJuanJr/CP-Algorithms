// - Descrición: Halla la ruta de costo minimo entre un nodo v y todos los demas
// - Complejidad: O(E + V log(V))

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

struct edge {
    int v;
    ll w;

    bool operator < (const edge &x) const {
        return w < x.w;
    }
};

int main() {
    int n, m; cin >> n >> m;
    vector<edge> ady[n];

    for (int i = 0; i < m; ++i) {
        int v, u;
        ll w;
        cin >> v >> u >> w;
        v--, u--;
        ady[v].push_back({u, w});
    }

    vector<ll> dist(n, LONG_LONG_MAX);

    auto dijkstra = [&](edge v) {
        priority_queue<edge> pq;
        pq.push(v);
        dist[v.v] = 0;
        while (sz(pq)) {
            v = pq.top();
            pq.pop();
            if (dist[v.v] != v.w) continue;
            for (edge &u : ady[v.v]) {
                if (dist[u.v] > dist[v.v] + u.w) {
                    dist[u.v] = dist[v.v] + u.w;
                    pq.push({u.v, dist[u.v]});
                }
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (dist[i] == LONG_LONG_MAX) {
            dijkstra({i, 0});
        }
    }
    return 0;
}

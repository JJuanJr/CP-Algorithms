// - Descripción: Halla el costo total del arbol recubridor minimo de un grafo no dirigido y conexo
// - Complejidad: O(E * log(V))

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

struct dsu {
    vector<int> pad, tam;
    int size;

    dsu(int n): pad(n), tam(n, 1), size(n) {
        iota(pad.begin(), pad.end(), 0);
    }

    void make() {
        pad.push_back(sz(pad));
        tam.push_back(1);
        size++;
    }

    int find(int v) {
        if (v == pad[v]) return v;
        return pad[v] = find(pad[v]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (tam[a] < tam[b]) swap(a, b);
            pad[b] = a;
            tam[a] += tam[b];
            size--;
        }
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int count(int v) {
        return tam[find(v)];
    }
};

struct edge {
    int v, u, w;

    bool operator < (const edge &x) const {
        return w < x.w;
    }
};

int main() {
    vector<edge> edges;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int v, u, w; cin >> v >> u >> w;
        v--, u--;
        edges.push_back({v, u, w});
    }
    sort(edges.begin(), edges.end());
    dsu UF(n);
    int nodes = 0, mst = 0;
    for (edge &i : edges) {
        if (!UF.same(i.v, i.u)) {
            mst += i.w;
            UF.unite(i.v, i.u);
            nodes++;
        }
        if (nodes == n - 1) break;
    }
    cout << mst << endl;
    return 0;
}

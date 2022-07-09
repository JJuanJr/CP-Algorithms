// - Descripción: Encuentra el orden topologico
// - Complejidad: O(V + E)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int main() {
    int n, m; cin >> n >> m;
    vector<int> ady[n];
    vector<int> grado(n);
    for (int i = 0; i < m; ++i) {
        int v, u; cin >> v >> u;
        v--, u--;
        ady[v].push_back(u);
        grado[u]++;
    }

    vector<int> topo;
    queue<int> qu;

    for (int i = 0; i < n; ++i) {
        if (grado[i] == 0) qu.push(i);
    }

    while (sz(qu)) {
        int v = qu.front();
        qu.pop();
        topo.push_back(v);
        for (int &u : ady[v]) {
            if (--grado[u] == 0) {
                qu.push(u);
            }
        }
    }

    for (int &i : topo) cout << i << " ";
    cout << endl;
    return 0;
}

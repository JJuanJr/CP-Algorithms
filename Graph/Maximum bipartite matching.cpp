// - Descripción: Halla el numero maximo de aristas que agregan nodos al conjunto una sola vez 
// - Complejidad: O(n * m)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

vector<vector<int>> ady;
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (int &u : ady[v]) {
        if (mt[u] == -1 || try_kuhn(mt[u])) {
            mt[u] = v;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;

    mt.assign(m, -1);
    vector<bool> used1(n);
    for (int v = 0; v < n; ++v) {
        for (int &u : ady[v]) {
            if (mt[u] == -1) {
                mt[u] = v;
                used1[v] = true;
                break;
            }
        }
    }

    for (int v = 0; v < n; ++v) {
        if (used1[v]) continue;
        used.assign(n, false);
        try_kuhn(v);
    }

    for (int i = 0; i < m; ++i) {
        if (mt[i] != -1) {
            cout << mt[i] + 1 << " " << i + 1 << endl;
        }
    }
    return 0;
}

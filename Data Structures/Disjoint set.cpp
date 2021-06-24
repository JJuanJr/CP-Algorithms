// - Descripción: Estructura que permite realizar operaciones con conjuntos disjuntos
// - Complejidad: O(log(n))

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

    int same(int a, int b) {
        return find(a) == find(b);
    }

    int count(int v) {
        return tam[find(v)];
    }

};

int main() {
    
    return 0;
}

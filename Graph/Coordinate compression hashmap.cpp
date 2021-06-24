// - Descripción: Comprime el numero de cada nodo
// - Complejidad: O(E)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int main() {
    int n, m; cin >> n >> m;
	vector<int> ady[n];
	unordered_map<ll, int> um;

	for (int i = 0; i < m; ++i) {
		ll v, u; cin >> v >> u;

		if (!um.count(v)) um[v] = sz(um);
		if (!um.count(u)) um[u] = sz(um);

		ady[um[v]].push_back(um[u]);
		cout << um[v] << " -> " << um[u] << endl;
	}

    return 0;
}

// - Descripción: Comprime el numero de cada nodo
// - Complejidad: O(max(V, E) * log(V))

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int main() {
    int n, m; cin >> n >> m;

	vector<ll> nodes;
	vector<pair<ll, ll>> edges;

	for (int i = 0; i < m; ++i) {
		ll v, u; cin >> v >> u;

		nodes.push_back(v);
		nodes.push_back(u);
		edges.emplace_back(v, u);
	}

	sort(nodes.begin(), nodes.end());
	nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
	vector<int> ady[sz(nodes)];

	for (pair<ll, ll> &i : edges) {
		int v = lower_bound(nodes.begin(), nodes.end(), i.first) - nodes.begin();
		int u = lower_bound(nodes.begin(), nodes.end(), i.second) - nodes.begin();
		ady[v].push_back(u);
		cout << v << " -> " << u << endl;
	}
    return 0;
}

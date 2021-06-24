// - Descripción: Encuentra las componentes fuertemente conexas en un grafo dirigido
// - Complejidad: O(V + E)

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

	for (int i = 0; i < sz(comp); ++i) {
		cout << "Component #" << i + 1 << ":";
		for (int &j : comp[i]) {
			cout << " " << j + 1;
		}
		cout << endl;
	}
	return 0;
}

// - Descripción: Halla los puntos de articulacion
// - Complejidad: O(V + E)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int main() {
	int n, m; cin >> n >> m;
	vector<int> ady[n];
	while (m--) {
		int a, b; cin >> a >> b;
		a--, b--;
		ady[a].push_back(b);
		ady[b].push_back(a);
	}

	int t = 0;
	vector<int> tin(n, -1), low(n);
	function<void(int, int)> dfs = [&](int u,  int p) {
		tin[u] = low[u] = t++;
		int children = 0;
		for (int &v : ady[u]) {
			if (p == v) continue;
			if (tin[v] == -1) {
				children++;
				dfs(v, u);
				low[u] = min(low[u], low[v]);
				if (tin[u] <= low[v] && p != -1) {
					cout << "Articulation " << u + 1 << endl;
				}
			} else {
				low[u] = min(low[u], low[v]);
			}
		}
		if (p == -1 && children > 1) {
			cout << "Articulation " << u + 1 << endl;
		}
	};

	for (int i = 0; i < n; ++i) {
		if (tin[i] == -1) {
			dfs(i, -1);
		}
	}
    return 0;
}

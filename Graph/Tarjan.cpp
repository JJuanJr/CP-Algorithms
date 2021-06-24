// - Descripción: Encuentra las componentes fuertemente conexas de un grafo dirigido
// - Complejidad: O(V + E)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int main() {
    int n, m; cin >> n >> m;
	vector<int> ady[n];

	for (int i = 0; i < m; ++i) {
		int v, u; cin >> v >> u;
		v--, u--;
		ady[v].push_back(u);
	}

	vector<int> low(n), num(n, -1), comp(n);
	stack<int> st;
	int scc, cont;
	scc = cont = 0;
	const int INF = 1e9;

	function<void(int)> tarjan = [&](int v) {
		low[v] = num[v] = cont++;
		st.push(v);
		for (int &u : ady[v]) {
			if (num[u] == -1) tarjan(u);
			low[v] = min(low[v], low[u]);
		}

		if (low[v] == num[v]) {
			int u;
			do {
				u = st.top(); st.pop();
				low[u] = INF;
				comp[u] = scc;
			} while (u != v);
			scc++;
		}
	};

	for (int i = 0; i < n; ++i) {
		if (num[i] == -1) {
			tarjan(i);
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << i << " -> " << comp[i] << endl;
	}
    return 0;
}

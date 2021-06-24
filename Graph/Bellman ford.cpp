// - Descripción: Halla la ruta de costo minimo entre un nodo v y todos los demas
// - Complejidad: O(V * E)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

struct edge {
	int v, u, w;
};

const int INF = 1e6;
int n, m;
vector<edge> edges;

vector<int> bellman(int v) {
	vector<int> dist(n, INF);
	dist[v] = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (edge &j : edges) {
			if (dist[j.v] < INF) {
				dist[j.u] = min(dist[j.u], dist[j.v] + j.w);
			}
		}
	}
	return dist;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int v, u, w; cin >> v >> u >> w;
		v--, u--;
		edges.push_back({v, u, w});
	}

	vector<int> dist = bellman(0);

	for (int i = 0; i < n; ++i) {
		cout << i + 1 << " - " << dist[i] << endl;
	}
    return 0;
}

// - Descripción: Calcula el costo minimo del camino que visita cada nodo una sola vez
// - Complejidad: 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

vector<vector<pair<int, int>>> ady;
int n, m, target;
const int N = 18;
const int MASK = 1 << N;
const int INF = 1e7;
int dp[N][MASK];

int solve(int v, int mask) {
    if (mask == target) return 0;
    int &ans = dp[v][mask];
    if (ans != -1) return ans;
    ans = INF;
    for (auto &u : ady[v]) {
        if (!(mask & (1 << u.first))) {
            ans = min(ans, solve(u.first, mask | (1 << u.first)) + u.second);
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    target = (1 << n) - 1;
    ady.assign(n, {});
    for (int i = 0; i < m; ++i) {
        int v, u, w; cin >> v >> u >> w;
        v--, u--;
        ady[v].push_back({u, w});
        ady[u].push_back({v, w});
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, 1) << endl;
    return 0;
}

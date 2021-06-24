// - Descripción: Permite responder consultas de rangos de sumas sin actualizaciones
// - Complejidad: O(1)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int main() {
    int n; cin >> n;
	vector<int> val(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		val[i] += val[i - 1];
	}
	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		cout << val[b] - val[a - 1] << endl;
	}
    return 0;
}

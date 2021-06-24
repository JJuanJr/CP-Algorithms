// - Descripción: Permite responder consultas en rangos
// - Complejidad: O(1) para minimos o maximos

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())
const int MAX = 1e5 + 5;
const int K = 17; //log2(MAX) + 1
int st[MAX][K];
int arr[MAX];
int n;

void build() {
    for (int i = 0; i < n; ++i) st[i][0] = arr[i];

    for (int j = 0; j < K - 1; ++j) {
        for (int i = 0; i + (1 << (j + 1)) <= n; ++i) {
            st[i][j + 1] = min(st[i][j], st[i + (1 << j)][j]);
        }
    }
}

int rmq(int l, int r) {
    int j = 31 - __builtin_clz(r - l + 1);
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    build();

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << rmq(l, r) << endl;
    }
    return 0;
}

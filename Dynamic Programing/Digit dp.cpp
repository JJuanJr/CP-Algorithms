// - Descripción: Cuenta la cantidad de numeros entre [a, b] que no tienen digitos iguales seguidos
// - Complejidad: O(NUM_E * NUM_T)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

const int MOD = 998244353;
int tam, NUM[55], dp[55][2][2][11];

int solve(int i, bool menor, bool ncero, int last) {
    if (i == tam) return 1;
    int &ans = dp[i][menor][ncero][last];
    if (ans != -1) return ans;
    ans = 0;
    for (int dig = 0; dig <= 9; ++dig) {
        if (dig == last && (ncero || dig)) continue;
        if (menor || dig <= NUM[i]) {
            ans = (ans + solve(i + 1, menor || dig < NUM[i], ncero || dig, dig)) % MOD;
        }
    }
    return ans;
}

bool g(string s) {
    for (int i = 0; i < sz(s) - 1; ++i) {
        if (s[i] == s[i + 1]) return false;
    }
    return true;
}

int build(string s) {
    tam = sz(s);
    for (int i = 0; i < sz(s); ++i) {
        NUM[i] = s[i] - '0';
    }
    memset(dp, -1, sizeof dp);
    return solve(0, false, false, 10);
}

int main() {
    string l, r;
    while (cin >> l >> r) {
        cout << ((build(r) - build(l) + MOD) % MOD + g(l)) % MOD << endl;
    }
    return 0;
}

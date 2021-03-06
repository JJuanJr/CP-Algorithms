// - Descripción: Calcula los numeros primos en un rango, requiere calcular los numeros primos hasta la raiz del n maximo
// - Complejidad: O(n * log(log(n)))

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

vector<int> prime;

vector<ll> segmented_criba(ll l, ll r) {
    l = max(l, 2ll);
    vector<bool> vis(r - l + 1);
    for (int &pp : prime) {
        if ((ll) pp * pp > r) break;
        ll mn = (l + pp - 1) / pp;
        if (mn == 1ll) mn++;
        mn *= pp;
        for (ll i = mn; i <= r; i += pp) {
            vis[i - l] = true;
        } 
    }
    vector<ll> ans;
    for (int i = 0; i < sz(vis); ++i) {
        if (!vis[i]) ans.push_back(l + i);
    }
    return ans;
}

int main() {
    
    return 0;
}

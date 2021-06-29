// - Descripción: Exponenciacion binaria con modulo
// - Complejidad: O(log(n))

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    
    return 0;
}

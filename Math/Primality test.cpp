// - Descripción: Calcula si un numero es primo
// - Complejidad: O(sqrt(n))

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

bool isPrime(ll n) {
    if (n < 2 || (n != 2 && !(n & 1))) return false;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {

    return 0;
}

// - Descripción: Hallar el maximo comun divisor
// - Complejidad: O(log(min(a, b)))

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    
    return 0;
}

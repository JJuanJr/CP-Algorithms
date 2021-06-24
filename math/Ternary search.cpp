// - Descripción: Encuentra el punto maximo o minimo de una funcion
// - Comlejidad: O(log(n))

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

double f(double x) {
    return x;
}

double ternary_search(double l, double r) {
    double eps = 1e-9;
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);
        double f2 = f(m2);
        if (f1 < f2) l = m1;
        else r = m2;
    }
    return f(l);
}

int main() {
    
    return 0;
}

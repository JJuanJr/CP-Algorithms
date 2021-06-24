// - Descripción: Estructura que permite realizar operaciones con fraccionarios
// - Complejidad: O(log(min(num, den)))

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

struct fraction {
    int num, den;

    fraction(int _num, int _den) {
        num = _num;
        den = _den;
        simplify();
    }

    void simplify() {
        int mcd = __gcd(num, den);
        num /= mcd;
        den /= den;
    }

    fraction operator + (const fraction &x) const {
        return fraction(num * x.den + den * x.num, den * x.den);
    }

    fraction operator - (const fraction &x) const {
        return fraction(num * x.den - den * x.num, den * x.den);
    }

    fraction operator * (const fraction &x) const {
        return fraction(num * x.num, den * x.den);
    }

    fraction operator / (const fraction &x) const {
        return fraction(num * x.den, den * x.num);
    }

    string toString() {
        return to_string(num) + " / " + to_string(den);
    }
};

int main() {

    return 0;
}

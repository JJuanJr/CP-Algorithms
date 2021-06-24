// - Descripción: Permite realizar consultas por rangos y actualizaciones
// - Complejidad: O(log(n))

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

struct FenwickTree {
    vector<int> ft;

    FenwickTree(int n): ft(n + 1) {}

    FenwickTree(const vector<int> &arr): ft(sz(arr) + 1) {
        for (int i = 1; i <= sz(arr); ++i) {
            add(i, arr[i - 1]);
        }
    }

    int rsq(int b) {
        int sum = 0;
        for (; b; b -= b & -b) sum += ft[b];
        return sum;
    }

    int rsq(int a, int b) {
        return rsq(b) - rsq(a - 1);
    }

    void add(int b, int v) {
        for (; b < sz(ft); b += b & -b) ft[b] += v;
    }
};

int main() {
    
    return 0;
}

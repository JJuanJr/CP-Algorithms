// - Descripción: Permite actualizar y responder consultas en rangos 
// - Complejidad: O(sqrt(n))

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int n, S;
vector<int> arr, block;

void preCalc() {
    S = sqrt(n);
    block.assign(n / S + 1, 0);
    for (int i = 0; i < n; ++i) {
        block[i / S] += arr[i];
    }
}

int query(int l, int r) {
    int sum = 0;
    int b_l = l / S, b_r = r / S;
    if (b_l == b_r) {
        for (int i = l; i <= r; ++i) {
            sum += arr[i];
        }
    } else {
        for (int i = l, end = (b_l + 1) * S - 1; i <= end; ++i) {
            sum += arr[i];
        }

        for (int i = b_l + 1; i <= b_r - 1; ++i) {
            sum += block[i];
        }

        for (int i = b_r * S; i <= r; ++i) {
            sum += arr[i];
        }
    }
    return sum;
}

void update(int i, int new_val) {
    block[i / S] += new_val - arr[i];
    arr[i] = new_val;
}

int main() {
    
    return 0;
}

// - Descripción: Encuentra la secuencia creciente mas larga de un arreglo
// - Complejidad: O(n^2) o O(n * log(n)))

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int lis(const vector<int> &arr) {
    int n = sz(arr);
    vector<int> d(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }

    int ans = d[0];
    for (int i = 1; i < n; ++i) {
        ans = max(ans, d[i]);
    }
    return ans;
}

vector<int> lis_subeq(const vector<int> &arr) {
    int n = sz(arr);
    vector<int> d(n, 1), p(n, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }

    int ans = d[0], pos = 0;
    for (int i = 1; i < n; ++i) {
        if (d[i] > ans) {
            ans = d[i];
            pos = i;
        }
    }

    vector<int> subseq;
    while (pos != -1) {
        subseq.push_back(a[pos]);
        pos = p[pos];
    }
    reverse(subseq.begin(), subseq.end());
    return subseq;
}

int lis_bin(const vector<int> &arr) {
    int n = sz(arr);
    const int INF = int(1e9);
    vector<int> d(n + 1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; ++i) {
        int j = int(upper_bound(d.begin(), d.end(), arr[i]) - d.begin());
        if (d[j - 1] < arr[i] && arr[i] < d[j]) {
            d[j] = arr[i];
        }

    }

    int ans = 0;
    for (int i = n; i >= 0; --i) {
        if (d[i] < INF) {
            ans = i;
            break;
        }
    }
    return ans;
}

int main() {
    
    return 0;
}

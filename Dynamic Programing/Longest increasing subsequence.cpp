// - Descripción: Encuentra la secuencia creciente mas larga de un arreglo
// - Complejidad: O(n^2)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())


int main() {
    const int N = 1005;
    int n, arr[N], lis[N];
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            lis[i] = 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] < arr[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        } 

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, lis[i]);
        }
        cout << ans << endl;
    }
    return 0;
}

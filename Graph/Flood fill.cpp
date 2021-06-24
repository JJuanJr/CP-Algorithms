// - Descripción: Colorea y cuenta el tamaño de las componentes conexas de un grafo implicito
// - Complejidad: O(n^2)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int n, m;
const int MAX = 1e3;
char ady[MAX][MAX];
int mi[] = {1, 0, -1, 0};
int mj[] = {0, 1, 0, -1};

int floodfill(int i, int j, const char &a, const char &b) {
    if (i < 0 || i == n || j < 0 || j == m || ady[i][j] != a) return 0;
    ady[i][j] = b;
    int cont = 1;
    for (int v = 0; v < 4; ++v) {
        cont += floodfill(i + mi[v], j + mj[v], a, b);
    }
    return cont;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> ady[i][j];
        }
    }
    int tam = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ady[i][j] == '.') {
                tam += floodfill(i, j, '.', 'X');
            }
        }
    }
    cout << tam << endl;
    return 0;
}

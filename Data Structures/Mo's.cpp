// - Descripción: Permite responder consultas por rangos offline
// - Complejidad: O((n + q) * f(sqrt(n)))

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

int S, n, q;

struct query {
    int l, r, idx;
    query(int _l, int _r, int _idx): l(_l), r(_r), idx(_idx) {}

    bool operator < (const query &x) const {
        if (l / S != x.l / S) return l / S < x.l / S;
        return (l / S & 1) ?  r < x.r: r > x.r;
    }
};

vector<query> qu;
vector<int> ans;

void add(int x) {

}

void del(int x) {

}

int get_ans() {
    return -1;
}

void mo_s() {
    S = sqrt(n);
    sort(qu.begin(), qu.end());
    ans.resize(q);
    int l = 0, r = -1;
    for (query &it: qu) {
        while (r < it.r) add(++r);
        while (l > it.l) add(--l);
        while (r > it.r) del(r--);
        while (l < it.l) del(l++);
        ans[it.idx] = get_ans();
    }
}

int main() {
    
    return 0;
}

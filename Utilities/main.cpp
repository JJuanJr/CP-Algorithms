#include <bits/stdc++.h>
using namespace std;

void _print() { cerr << "]" << endl; }
template<typename T, typename... V>
void _print(T t, V... v) { cerr << t; if (sizeof...(v)) cerr << ", "; _print(v...); }

#ifdef LOCAL
    #define dbg(x...) cerr << "[" << #x << "]: ["; _print(x)
#else
    #define dbg(x...)
    #define endl '\n'
#endif
#define ll long long
#define sz(x) int(x.size())

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    return 0;
}

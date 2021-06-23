#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) int(x.size())

const int MAX = 1e6;
bitset<MAX + 5> bs;
vector<int> prime;

void criba() {
    bs.set();
    for (int i = 2; i <= MAX; ++i) {
        if (bs[i]) {
            prime.push_back(i);
            for (ll j = (ll) i * i; j <= MAX; j += i) {
                bs[j] = 0;
            }
        }
    }
}

int main() {
    criba();
    
    return 0;
}

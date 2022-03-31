#include <iostream>
using namespace std;

typedef long long ll;


ll modpow(ll a, ll e, ll m) {
    __int128_t r = 1, b = a % m;
    while (e > 0) {
        if (e & 1)
            r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

bool check_composite(ll n, ll a, ll d, int s) {
    auto x = modpow(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (__int128_t)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool isPrime_MillerRabin(ll x) {
    if (x < 2)
        return false;
    int r = 0;
    ll d = x - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (x == a)
            return true;
        if (check_composite(x, a, d, r))
            return false;
    }
    return true;
}



void solve() {
    ll n; cin >> n;
    cout << isPrime_MillerRabin(n) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
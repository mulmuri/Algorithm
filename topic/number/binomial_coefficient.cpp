#include <iostream>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
typedef long long ll;

const int MOD = 1000000007;
const int SIZE = 4000001;



ll fact[SIZE];
ll invfac[SIZE];

ll pow(ll a, ll e) {
    ll r = 1, b = a % MOD;
    while (e > 0) {
        if (e & 1)
            r = r * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return r;
}

ll inv(ll x) {
    return pow(x, MOD-2);
}

ll comb(ll n, ll k) {
    ll r = (fact[n] * invfac[n - k]) % MOD;
    r = r * invfac[r] % MOD;

    return r;
}



int n,r;

void solve() {
    cin >> n >> r;
    cout << comb(n, r) << endl;
}

int main() {
    fact[0] = 1;
    for (int i=1; i<SIZE; i++)
        fact[i] = fact[i-1] * i % MOD;

    invfac[SIZE-1] = inv(fact[SIZE-1]);
    for (int i=SIZE-2; i; i--)
        invfac[i] = invfac[i+1] * (i+1) % MOD;

    int t; cin >> t;
    while (t--) solve();    
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long
typedef long long ll;

const int MOD = 998244353;
const int INF = 1e18;
const int SIZE = 400001;



ll fact[SIZE];
ll invf[SIZE];

ll power(ll a, ll e) {
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
    return power(x, MOD-2);
}

ll comb(ll n, ll r) {
    return fact[n] * invf[r] % MOD * invf[n-r] % MOD;
}

ll catalan(int n) {
    return fact[n*2] * invf[n+1] % MOD * invf[n] % MOD;
}

void math_init(int n) {
    fact[0] = 1;
    for (int i=1; i<SIZE; i++) fact[i] = fact[i-1] * i % MOD;
    invf[SIZE-1] = inv(fact[SIZE-1]);
    for (int i=SIZE-2; i>=0; i--) invf[i] = invf[i+1] * (i+1) % MOD;
}



int n;


int32_t main() {
    fastio;

    cin >> n;
    math_init(n);
    cout << power(2, n) * fact[n] % MOD * catalan(n) % MOD;
}
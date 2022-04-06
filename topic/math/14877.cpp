#include <iostream>
using namespace std;


typedef long long ll;
const int MOD = 1e9+7;
const int SIZE = 200001;



int n;

ll dp[SIZE];
ll arr[SIZE];
ll psum[SIZE];

ll fact[SIZE];
ll invf[SIZE];

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
    return fact[n] * invf[k] % MOD * invf[n-k] % MOD;
}


int main() {
    cin >> n;

    //int a; for (int i=0; i<n; i++) cin >> a;

    fact[0] = 1;
    for (ll i=1; i<=n; i++) fact[i] = fact[i-1] * i % MOD;
    invf[n] = inv(fact[n]);
    for (ll i=n-1; i>=0; i--) invf[i] = invf[i+1] * (i+1) % MOD;


    dp[0] = 1;
    dp[1] = 0; dp[2] = 1;
    for (ll i=3; i<=n; i++) dp[i] = (dp[i-1] + dp[i-2]) * (i-1) % MOD;
    for (ll i=0; i<=n; i++) arr[i] = dp[i] * comb(n, i) % MOD;
    for (ll i=3; i<=n; i++) psum[i] = (psum[i-1] + arr[i]) % MOD;

    for (int i=1; i<n; i++) {
        ll sum = psum[min(i*2, n)];
        if (i%2 == 0) sum = (sum + arr[0]) % MOD;
        else sum = (sum + arr[2]) % MOD;
        
        cout << sum <<' ';
    }

}
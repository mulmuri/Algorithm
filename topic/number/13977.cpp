#include <iostream>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
typedef long long ll;

const ll MOD = 1000000007;
const int SIZE = 4000001;


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

ll comb(ll n, ll r) {
    return fact[n] * invf[r] % MOD * invf[n-r] % MOD;
}



ll n,k;

int main() {
    fact[0] = 1;
    for (int i=1; i<SIZE; i++) fact[i] = fact[i-1] * i % MOD;
    invf[SIZE-1] = inv(fact[SIZE-1]);
    for (int i=SIZE-2; i>=0; i--) invf[i] = invf[i+1] * (i+1) % MOD;

    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << comb(n, k) << endl;
    }

}
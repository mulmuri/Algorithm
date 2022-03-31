#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long
typedef long long ll;

const int MOD = 998244353;
const int SIZE = 100001;



int n, k;
ll arr[SIZE];
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

ll comb(ll n, ll r) {
    ll c = invfac[r];
    for (int i=0; i<r; i++) {
        c = c * (n-i) % MOD;
    }
    return c;
}


int32_t main() {
    fastio;
    
    cin >> n >> k;    
    for (int i=1; i<=n; i++) cin >> arr[i];

    ll sum = 0;
    for (int i=2; i<=n; i++) sum += arr[i];

    if (arr[1] < sum+k) {
        cout << 0;
        return 0;
    }
    if (k == 1) {
        cout << 1;
        return 0;
    }
    arr[1] -= (sum + k);

    fact[0] = 1;
    for (int i=1; i<=k; i++) {
        fact[i] = fact[i-1] * i % MOD;
        invfac[i] = inv(fact[i]);
    }


    ll ans = 1;
    for (int i=1; i<=n; i++) ans = ans * comb(arr[i] + k-1, k-1) % MOD;
    cout << ans;
}
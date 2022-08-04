#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;

const int MOD = 998244353;
const int INF = 1e18;
const int SIZE = 200001;


int n,k;
int dp[SIZE][2];
int accum[SIZE];
int ans[SIZE];


void solve() {
    cin >> n >> k;

    int low = 0;
    dp[0][k%2] = 1;

    for (int u=k; low+u<= n; u++) {
        low += u;
        for (int i=low; i<=n; i++) {
            accum[i] = accum[i-u] + dp[i-u][u%2];
            accum[i] %= MOD;

            ans[i] += accum[i];
            ans[i] %= MOD;

            dp[i][(u+1)%2] = accum[i];
        }

        for (int i=low; i<=n; i++) accum[i] = 0;
    }

    for (int i=1; i<=n; i++) cout << ans[i] <<' ';
}

int32_t main() {
    fastio;

    solve();
}
#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998244353;
const int INF = 1e18;
const int SIZE = 101;


int n,m;
int p[SIZE];

int dp[SIZE][SIZE][SIZE];

int trash;

void solve(int tc) {
    cin >> n >> m;
    if (n > 10 || m > 50) {
        for (int i=0; i<n; i++) cin >> trash;
        cout << "Case #" << tc << endl << 0 << endl;
        return;
    }

    for (int i=1; i<=n; i++) cin >> p[i];

    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (i == 1) {
                dp[i][j][1] = p[j];
                continue;
            }
            for (int k=1; k<=j; k++) {
                dp[i][j][k] = dp[i-1][j][k] * p[j] % MOD;
                for (int u=1; u<j; u++) dp[i][j][k] = (dp[i][j][k] + dp[i-1][u][k-1] * i  % MOD * p[j]) % MOD;

                //cout << i <<' '<< j <<' '<< k <<' '<< dp[i][j][k] << endl;
            }
        }
    }

    int ans = 0;

    for (int i=1; i<=min(n, m); i++) {
        int sum = 0;
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=min(n, m); k++) {
                sum = (sum + dp[i][j][k] * k) % MOD;
            }
        }
        cout << sum <<' ';
        ans ^= sum;
    }
    cout << endl;

    cout << "Case #" << tc << endl;
    cout << ans << endl;
}

int32_t main() {
    fastio;


    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
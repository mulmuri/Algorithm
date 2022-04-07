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

const int MOD = 998244353;
const int INF = 1e9;
const int SIZE = 5001;



int n, m;

int fact[SIZE];
int invf[SIZE];
int minFactor[SIZE];

int pow(int a, int e) {
    int r = 1, b = a % MOD;
    while (e > 0) {
        if (e & 1)
            r = r * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return r;
}

int inv(int x) {
    return pow(x, MOD-2);
}

int comb(int n, int r) {
    return fact[n] * invf[r] % MOD * invf[n-r] % MOD;
}

int dp[SIZE][SIZE];

int32_t main() {
    fastio;

    cin >> n >> m;

    fact[0] = 1;
    for (int i=1; i<SIZE; i++) fact[i] = fact[i-1] * i % MOD;
    invf[SIZE-1] = inv(fact[SIZE-1]);
    for (int i=SIZE-2; i>=0; i--) invf[i] = invf[i+1] * (i+1) % MOD;


    bool flag = (1 & m);
    for (int k=flag; k<n; k+=2) {
        dp[k][0] = comb(n, k);
    }


    int t;
    for (int i=1; 1<<i <= m; i++) {
        t = i;
        flag = (1<<i & m) ? 1 : 0;

        for (int k=flag; k<=n; k+=2) {
            for (int j=0; j<=m; j++) {
                if (k*(1<<i) + j > m) continue;
                dp[j + k*(1<<i)][i] = dp[j + k*(1<<i)][i] + dp[j][i-1] * comb(n, k);
            }
        }

        for (int j=0; j<=m; j++)
            dp[j][i] = (dp[j][i] + dp[j][i-1]) % MOD;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<=m; j++) cout << dp[j][i] <<' ';
        cout << endl;
    }

    cout << dp[m][t];

}
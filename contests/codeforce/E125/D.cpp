#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl "\n"
#define MOD 998244353
#define INF 1e9
#define SIZE 501

#define int long long



long long power(long long n, long long r) {
    if (r < 0) return 0;
    long long ret = 1;
    for (; r; r >>= 1) {
        if (r & 1) ret = ret * n % MOD;
        n = n * n % MOD;
    }
    return ret;
}


int n,k;

int comb[SIZE][SIZE];

int32_t main() {
    cin >> n >> k;

    for (int i=0; i<=n; i++) comb[i][0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
        }
    }

    int ans = 0;

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<=k; j++) {
            for (int u=1; u<=k; u++) {
                int a = power(u-1, i);
                int b = comb[j-i][n-1-i] * comb[j-i][n-1-i];
                int c = power(k-u, (n-1)*(n-2) - j);
                int result = a * b % MOD * c % MOD;
                ans += result;
            }
        }
    }

    cout << ans;
}
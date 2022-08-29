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
const int SIZE = 300001;


int n;
int arr[SIZE];

map<int,int> dp;

int f(int x) {
    if (x <= 4) return x;
    if (dp[x]) return dp[x];

    dp[x/2] = f(x/2);
    dp[(x+1)/2] = f((x+1)/2);
    return dp[x/2] * dp[(x+1)/2] % MOD;
}

int32_t main() {
    fastio;

    cin >> n;
    cout << f(n);

}
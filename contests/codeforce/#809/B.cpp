#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;
typedef pair<int,int> pii;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200001;


int n;

int dp[SIZE][2];


void solve() {
    cin >> n;
    for (int i=0; i<=n; i++) dp[i][0] = dp[i][1] = 0;

    for (int i=1; i<=n; i++) {
        int t; cin >> t;

        dp[t][i%2] = dp[t][(i+1)%2] + 1;
    }
    for (int i=1; i<=n; i++) cout << max(dp[i][0], dp[i][1]) <<' ';
    cout << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
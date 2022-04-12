#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define int long long
typedef long long ll;
#define INF 1e9
#define MOD 998244353
#define SIZE 5001

int arr[SIZE];
int n,m,k;

vector<int> adj[SIZE];

int dp[SIZE][2];

int32_t main() {
    cin >> n >> m >> k;

    for (int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int sum = 1;
    dp[1][0] = 1;

    for (int i=1; i<=k; i++) {

        for (int j=1; j<=n; j++) {
            dp[j][i%2] = sum;
        }

        for (int j=1; j<=n; j++) {
            for (auto k: adj[j]) {
                dp[j][i%2] -= dp[k][(i+1)%2];
            }
            dp[j][i%2] -= dp[j][(i+1)%2];
        }

        for (int j=1; j<=n; j++) {
            dp[j][i%2] %= MOD;
        }

        sum = 0;
        for (int j=1; j<=n; j++) {
            sum += dp[j][i%2];
        }
    }

    cout << dp[1][k%2];
}

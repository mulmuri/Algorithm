#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 300001;


int n;
vector<pair<int,int>> adj[SIZE];
int d[SIZE];
int dp[SIZE][2];


void dfs(int t, int p) {
    int def = 0;
    vector<int> dif;

    for (auto[w, n]: adj[t]) {
        if (n == p) continue;

        dfs(n, t);

        def += dp[n][0];

        if (d[n] == 0) dif.push_back(0);
        else dif.push_back(dp[n][1] + w - dp[n][0]);
    }

    sort(dif.begin(), dif.end(), greater<>());

    dp[t][0] = dp[t][1] = def;
    for (int i=0; i<min(d[t], (int)dif.size()); i++) dp[t][0] += max((int)0, dif[i]);
    for (int i=0; i<min(d[t]-1, (int)dif.size()); i++) dp[t][1] += max((int)0, dif[i]);
}



int32_t main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> d[i];

    for (int i=1; i<n; i++) {
        int u,v,w;
        cin >> u >> v >> w;

        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }

    dfs(1, 0);

    cout << max(dp[1][0], dp[1][1]) << endl;
    for (int i=1; i<=n; i++) cout << dp[i][0] <<' '; cout << endl;
    for (int i=1; i<=n; i++) cout << dp[i][1] <<' '; cout << endl;



}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define int long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define MOD 998244353
#define INF 2e9
#define SIZE 200001



int n;

int ans[SIZE];
vector<int> adj[SIZE];
pair<int,int> dp[SIZE][2];

vector<pair<int,int>> adj2[SIZE][2];

void dfs(int t, int p) {
    for (auto n: adj[t]) {
        if (n == p) continue;

        dfs(n, t);

        // white
        if (dp[n][0].first > dp[n][1].first) {
            dp[t][0].first += dp[n][0].first;
            dp[t][0].second += dp[n][0].second;
            adj2[t][0].push_back({n,0});
        } else if (dp[n][0].first < dp[n][1].first) {
            dp[t][0].first += dp[n][1].first;
            dp[t][0].second += dp[n][1].second;
            adj2[t][0].push_back({n,1});
        } else {
            dp[t][0].first += dp[n][0].first;

            if (dp[n][0].second > dp[n][1].second) {
                dp[t][0].second += dp[n][1].second;
                adj2[t][0].push_back({n,1});
            } else {
                dp[t][0].second += dp[n][0].second;
                adj2[t][0].push_back({n,0});
            }
        }

        //black
        dp[t][1].first += dp[n][0].first;
        dp[t][1].second += dp[n][0].second;

        adj2[t][1].push_back({n,0});
    }

    dp[t][1].first++;
    dp[t][1].second += adj[t].size();
}

void dfs2(int t, int p, int i) {
    ans[t] = i;

    for (auto e: adj2[t][i]) {
        int n = e.first;
        int j = e.second;
        if (n == p) continue;

        dfs2(n, t, j);
    }

}


int32_t main() {
    fastio;

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (n == 2) {
        cout << 2 <<' '<< 2 << endl << 1 <<' '<< 1;
        return 0;
    }

    dfs(1, 0);

    if (dp[1][0].first > dp[1][1].first) {
        cout << dp[1][0].first <<' '<< dp[1][0].second + n - dp[1][0].first << endl;
        dfs2(1, 0, 0);
    } else {
        cout << dp[1][1].first <<' '<< dp[1][1].second + n - dp[1][1].first << endl;
        dfs2(1, 0, 1);
    }
    
    for (int i=1; i<=n; i++) {
        if (ans[i] == 0) cout << 1 <<' ';
        else cout << adj[i].size() <<' ';
    }
}
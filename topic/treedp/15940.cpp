#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long
const int SIZE = 200001;



int n;
vector<pair<int,int>> adj[SIZE];

pair<int,int> dp1[SIZE];
pair<int,int> dp2[SIZE];

int ans = 0;



void dfs1(int t, int p) {
    vector<int> dp;
    for (int i=0; i<adj[t].size(); i++) {
        int n = adj[t][i].first;
        if (n == p) continue;
        int l = adj[t][i].second;

        dfs1(n, t);

        dp.push_back(dp1[n].second + l);
        dp1[t].first = max(dp1[t].first, dp1[n].first);

        dp1[t].second = max(dp1[t].second, dp1[n].second + l);
    }

    int nv;
    if (dp.size() == 0) return;
    else if (dp.size() == 1) nv = dp[0];
    else {
        sort(dp.begin(), dp.end(), greater<>());
        nv = dp[0] + dp[1];
    }

    dp1[t].first = max(dp1[t].first, nv);
}

void dfs2(int t, int p) {
    vector<int> dp;
    for (int i=adj[t].size()-1; i; i--) {
        int n = adj[t][i].first;
        if (n == p) continue;
        int l = adj[t][i].second;

        dfs2(n, t);

        dp.push_back(dp2[n].second + l);
        dp2[t].first = max(dp2[t].first, dp2[n].first);

        dp2[t].second = max(dp2[t].second, dp2[n].second + l);
    }

    int nv;
    if (dp.size() == 0) return;
    else if (dp.size() == 1) nv = dp[0];
    else {
        sort(dp.begin(), dp.end(), greater<>());
        nv = dp[0] + dp[1];
    }

    dp2[t].first = max(dp2[t].first, nv);
}

void dfs3(int t, int p) {
    for (int i=0; i<adj[t].size(); i++) {
        int n = adj[t][i].first;
        if (n == p) continue;
        int l = adj[t][i].second;

        ans = max(ans, dp1[n].first + dp2[t].first + l);
        if (ans == 8) {
            cout << dp1[n].first <<' '<< dp2[t].first << ' '<< n <<' '<< t << endl;
        }
    }
}



int32_t main() {
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    int st;
    for (int i=1; i<=n; i++) {
        if (adj[i].size() == 1) {
            st = i;
            break;
        }
    }

    dfs1(st, 0);
    dfs2(st, 0);
    dfs3(st, 0);

    cout << ans;
}
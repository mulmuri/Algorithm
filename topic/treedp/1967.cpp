#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int SIZE = 200001;



int n;
vector<pair<int,int>> adj[SIZE];

pair<int,int> dp1[SIZE];
pair<int,int> dp2[SIZE];

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



int main() {
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    dfs1(1, 0);

    cout << dp1[1].first;
}
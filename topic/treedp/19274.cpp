#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int SIZE = 100000;

int n;
vector<int> adj[SIZE];
int vst[SIZE];
int dp[SIZE];

void dfs(int t) {
    vst[t] = 1;
    int cnt = 0;
    for (int n: adj[t]) {
        if (vst[n]) continue;
        dfs(n);
        dp[t] += dp[n];
        if (dp[n] == 0) cnt++;
    }
    dp[t] += max(0, cnt-1);
}

int dfs2(int t) {
    vst[t] = 1;
    if (adj[t].size() <= 2) {
        for (int n: adj[t]) {
            if (vst[n]) continue;
            return dfs2(n);
        }
    } else {
        for (int n: adj[t]) {
            if (vst[n]) continue;
            if (dp[n] == 0) return 1;
        }
        return 0;
    }
    return 1;
}

int main() {
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a,b; 
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i=0; i<n; i++) {
        if (adj[i].size() == 1) {
            dfs(i);
            fill(vst, vst+n, 0);
            cout << dp[i] + dfs2(i);
            return 0;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

const int SIZE = 100001;
const int INF = 1e8;



int n;
vector<int> adj[SIZE];
map<int,int> merged[SIZE];
int color[SIZE];

int ans = INF;


int dfs(int t, int p, int lv) {
    merged[t][color[t]] = lv;
    
    int to = t;
    int from;

    for (int n: adj[t]) {
        if (n == p) continue;

        from = dfs(n, t, lv+1);

        if (merged[to].size() < merged[from].size()) swap(from, to);

        for (auto it=merged[from].begin(); it!=merged[from].end(); it++) {
            if (merged[to][it->first]) {
                ans = min(ans, merged[to][it->first] + it->second - 2*lv);
                merged[to][it->first] = min(merged[to][it->first], it->second);
            }
            else merged[to][it->first] = it->second;
        }
    }

    return to;

}



int main() {
    cin >> n;    
    for (int i=1; i<=n; i++) cin >> color[i];
    
    for (int i=1; i<n; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);

    cout << ans;
}
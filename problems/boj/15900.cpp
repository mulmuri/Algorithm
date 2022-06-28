#include <iostream>
#include <vector>
using namespace std;




const int SIZE = 500001;


int n;
int depth[SIZE];
vector<int> adj[SIZE];

void dfs(int t, int p, int lv) {
    if (adj[t].size() == 1) depth[t] = lv;
    for (auto n: adj[t]) {
        if (n == p) continue;
        dfs(n, t, lv+1);
    }
}


int main() {
    cin >> n;
    for (int i=1; i<n; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);

    int ans = 0;
    for (int i=1; i<=n; i++) ans += depth[i];

    if (ans%2 == 0) cout << "No";
    else cout << "Yes";
}
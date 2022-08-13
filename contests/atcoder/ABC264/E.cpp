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
const int SIZE = 500001;


int n,m,e,q;
int arr[SIZE];
int broken[SIZE];
pair<int,int> edge[SIZE];
int query[SIZE];

vector<int> adj[SIZE];
int vst[SIZE];
vector<int> ans;

int cnt = 0;



void dfs(int now) {
    if (vst[now] == 0) cnt++;
    if (vst[now] > 100) return;

    vst[now]++;

    for (int nxt: adj[now]) {
        if (!vst[nxt]) dfs(nxt);
    }
}


int32_t main() {
    fastio;
    
    cin >> n >> m >> e;
    for (int i=1; i<=e; i++) cin >> edge[i].first >> edge[i].second;

    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> query[i];
        broken[query[i]] = 1;
    }

    for (int i=1; i<=e; i++) {
        if (!broken[i]) {
            auto[u,v] = edge[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    for (int i=n+1; i<=n+m; i++) if (!vst[i]) dfs(i);

    cout << endl;

    //ans.push_back(cnt - m);

    


    for (int i=q; i; i--) {
        auto[u,v] = edge[query[i]];

        adj[u].push_back(v);
        adj[v].push_back(u);

        if (vst[u]) dfs(v);
        if (vst[v]) dfs(u);

        ans.push_back(cnt - m);
    }

    reverse(ans.begin(), ans.end());
    for (auto e: ans) cout << e << endl;
}


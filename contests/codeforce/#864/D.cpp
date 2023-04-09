#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 300001;


int n,k;
int w[SIZE];
int wsum[SIZE];
int pr[SIZE];
int son[SIZE];
int cnt[SIZE];

vector<int> adj[SIZE];
int vst[SIZE];

int dfs(int t, int p) {
    int s = w[t];
    for (int n: adj[t]) {
        if (n == p) continue;
        pr[n] = t;
        s += dfs(n, t);
    }
    
    int pw = 0;
    for (int n: adj[t]) {
        if (wsum[pw] < wsum[n]) {
            pw = n;
        }
    }
    son[t] = pw;

    wsum[t] = s;

    return wsum[t];
}



void solve() {
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> w[i];

    for (int i=1; i<n; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=1; i<=n; i++) cnt[i] = adj[i].size() - 1;

    dfs(1, 0);

    while (k--) {
        int t,x; cin >> t >> x;
        if (t == 2) {
            int child = son[x];
            int parent = pr[x];

            if (cnt[child] == 0) continue;
            cnt[child]++;
            cnt[x]--;

            if (son[parent] == x) son[parent] = child;
            if (son[x] == child) 

            pr[child] = parent;
            pr[x] = child;
            int tmp = wsum[x];
            wsum[x] = wsum[x] - wsum[child];
            wsum[child] = tmp;

            if (wsum[son[child]] < wsum[x]) son[child] = x;

        } else {
            cout << wsum[x] << endl;
        }
    }
}

int32_t main() {
    fastio;

    solve();
}
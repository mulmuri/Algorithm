#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;
typedef pair<int,int> pii;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200001;


int n,t;
int p[SIZE];
int l[SIZE];
int r[SIZE];
vector<int> adj[SIZE];
int dp[SIZE];

int cnt = 0;



void dfs(int t) {
    if (adj[t].size() == 0) {
        cnt++;
        dp[t] = r[t];
        return;
    }

    for (int n: adj[t]) dfs(n);

    int v = 0;
    for (int n: adj[t]) v += dp[n];
    if (v >= l[t]) dp[t] = min(r[t], v);
    else {
        cnt++;
        dp[t] = r[t];
    }
}


void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) adj[i].clear();
    cnt = 0;

    for (int i=2; i<=n; i++) {
        int p; cin >> p;
        adj[p].push_back(i);
    }
    for (int i=1; i<=n; i++) cin >> l[i] >> r[i];

    dfs(1);

    cout << cnt << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
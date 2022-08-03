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


int n,m;
int arr[SIZE];
pair<int,int> edge[SIZE];
vector<int> adj[SIZE];


void solve() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) adj[i].clear();

    for (int i=1; i<=n; i++) cin >> arr[i];
    for (int i=1; i<=m; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge[i] = {u,v};
    }

    int val = 0;

    if (m%2 != 0) {
        val = INF;
        for (int i=1; i<=n; i++) if (adj[i].size()%2 != 0) val = min(val, arr[i]);
        for (int i=1; i<=m; i++) {
            auto[u,v] = edge[i];
            if ((adj[u].size() + adj[v].size())%2 == 0) val = min(val, arr[u] + arr[v]);
        }
    }

    cout << val << endl;

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
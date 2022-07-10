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


int n;
int vst[SIZE];
vector<int> adj[SIZE];




int bfs(int t) {
    int cnt = 1;
    for (auto n: adj[t]) {
        if (vst[n]) continue;
        vst[n] = 1;
        cnt += bfs(n);
    }
    return cnt;
}


void solve() {
    cin >> n;
    fill(vst, vst+n+1, 0);
    for (int i=1; i<=n; i++) adj[i].clear();

    int flag = 0;

    for (int i=0; i<n; i++) {
        int u,v; cin >> u >> v;
        if (u == v) flag = 1;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (flag) {
        cout << "NO" << endl;
        return;
    }

    for (int i=1; i<=n; i++) {
        if (adj[i].size() != 2) {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i=1; i<=n; i++) {
        if (vst[i] == 0) {
            vst[i] = 1;
            if (bfs(i)%2) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
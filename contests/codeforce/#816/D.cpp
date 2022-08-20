#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200001;


int n,q;

vector<pair<int,int>> adj[SIZE][30];


void solve() {
    cin >> n >> q;

    while (q--) {
        int u,v,x; cin >> u >> v >> x;

        for (int i=0; i<30; i++) {
            bool w = (x & (1<<i));

            adj[u][i].push_back({v,w});
            adj[v][i].push_back({u,w});
        }
    }
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
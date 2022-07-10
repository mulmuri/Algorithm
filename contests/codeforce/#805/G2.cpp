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


int n, q;
int target[SIZE];
vector<int> adj[SIZE];
vector<int> adj2[SIZE];
int vst[SIZE];


void dfs(int t, int p) {
    for (auto n: adj[t]) {
        if (n == p) continue;

        if (vst[n] == 0) {
            vst[n] = 1;
            adj2[t].push_back(n);
            adj2[n].push_back(t);
            if (p != 0) {
                adj2[p].push_back(n);
                adj2[n].push_back(p);
            }
            dfs(n, t);
        }
    }
}

pair<int,int> dfs2(int t, int p) {
    int cnt = 0;
    int val;
    for (auto n: adj2[t]) {
        if (target[n] == 0) continue;
        if (n == p) continue;

        if (vst[n] == 0) {
            vst[n] = 1;
            auto[d, newval] = dfs2(n, t);
            if (cnt < d) {
                cnt = d;
                val = newval;
            }
        }
    }
    return {cnt+1, val};
}


int32_t main() {
    fastio;

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);
    fill(vst, vst+n+1, 0);

    cin >> q;
    while (q--) {
        int k; cin >> k;
        vector<int> set;
        for (int i=0; i<k; i++) {
            int v; cin >> v;
            set.push_back(v);
        }

        for (int i=0; i<k; i++) target[set[i]] = 1;
        auto[d1, val1] = dfs2(set[0], 0);

        for (int i=0; i<k; i++) vst[set[i]] = 0;
        auto[d2, val2] = dfs2(val1, 0);

        cout << ((d1 <= 2) ? "YES" : "NO") << endl;
        for (int i=0; i<k; i++) vst[set[i]] = 0;
        for (int i=0; i<k; i++) target[set[i]] = 0;
    }
}
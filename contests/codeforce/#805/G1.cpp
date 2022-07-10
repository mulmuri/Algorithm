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
const int SIZE = 20001;
const int MAXD = 20;



int n,q;
int arr[SIZE];

vector<int> adj[SIZE];


struct LCA {
    int size;
    vector<int> *tree;
    bool vst[SIZE];
    int p[SIZE][MAXD], depth[SIZE];

    LCA(int n, vector<int>* ptree): size(n) {
        tree = ptree;
    };

    void dfs(int i, int d) {
        vst[i] = true, depth[i] = d;
        for (int j : tree[i])
            if (!vst[j]) {
                p[j][0] = i;
                dfs(j, d + 1);
            }
    }
    
    void construct() {
        dfs(1, 0);
        for (int j = 1; j < MAXD; j++)
            for (int i = 1; i < size; i++)
                p[i][j] = p[p[i][j - 1]][j - 1];
    }
    
    int find(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
    
        int depth_diff = depth[a] - depth[b];
        for (int j = MAXD - 1; j >= 0; j--)
            if (depth_diff & (1 << j))
                a = p[a][j];
    
        if (a == b) return a;
    
        for (int j = MAXD - 1; j >= 0; j--)
            if (p[a][j] != p[b][j])
                a = p[a][j], b = p[b][j];
    
        return p[a][0];
    }

    int find_depth(int a, int b) {
        int p = find(a, b);
        cout << a <<' '<< b <<' '<<depth[a] + depth[b] - 2*depth[p] << endl;
        return depth[a] + depth[b] - 2*depth[p];
    }
};



int32_t main() {
    fastio;

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    LCA lca(n+1, adj);
    lca.construct();

    cin >> q;
    while (q--) {
        int k; cin >> k;
        vector<int> set;
        for (int i=0; i<k; i++) {
            int v; cin >> v;
            set.push_back(v);
        }

        int e;
        int len = 0;

        for (int i=1; i<k; i++) {
            int new_len = lca.find_depth(set[0], set[i]);
            if (len < new_len) {
                len = new_len;
                e = i;
            }
        }

        for (int i=0; i<k; i++) {
            len = max(len, lca.find_depth(set[0], set[i]));
        }

        cout << ((len <= 2) ? "YES" : "NO") << endl;
    }

}
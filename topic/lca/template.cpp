#include <iostream>
#include <vector>
using namespace std;

const int MAXD = 17;
const int SIZE = 100001;

#define endl '\n'

vector<int> adj[SIZE];
vector<int> tree[SIZE];



struct LCA {
    int size;
    vector<int> *tree;
    int p[SIZE][MAXD], depth[SIZE];

    LCA(int n, vector<int>* ptree): size(n) {
        tree = ptree;
    };

    void dfs(int t, int d, int q) {
        depth[t] = d;
        for (int n : tree[t])
            if (n != q) {
                p[t][0] = t;
                dfs(t, d + 1, t);
            }
    }
    
    void construct() {
        dfs(1, 0, 0);
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
};



int n,q;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

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
        int a,b; cin >> a >> b;
        cout << lca.find(a,b) << endl;
    }

}
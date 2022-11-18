#include <bits/stdc++.h>
using namespace std;

const int SIZE = 10001;


int parent[SIZE];
vector<int> adj[SIZE];

int n,m;



int find(int p) {
    if (p == parent[p]) return p;
    parent[p] = find(parent[p]);
}


void merge(int p, int q) {
    
}




int solve() {
    cin >> n >> m;
    if (n == 0 && m == 0) return 0;

    for (int i=1; i<=n; i++) adj[i].clear();
    iota(parent, parent+n+1, 0);

    for (int i=1; i<=m; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    


}


int main() {
    while (solve());
}
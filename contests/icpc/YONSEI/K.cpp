#include <bits/stdc++.h>
using namespace std;

const int SIZE = 500001;



int n,k;
vector<int> adj[SIZE];
int depth[SIZE];


int st, ed;

void dfs(int t, int p, int d) {
    depth[t] = d;

    for (int n: adj[t]) {
        if (n == p) continue;

        dfs(n, t, d+1);
    }
}

vector<int> stk;
int flag = 0;

void getCriticalPath(int t, int p) {
    if (flag == 0) stk.push_back(t);
    if (t == ed) flag = 1;
    
    for (int n: adj[t]) {
        if (n == p) continue;

        getCriticalPath(n, t);
    }

    if (flag == 0) stk.pop_back();
}


int lft;
int vst[SIZE];

int before;

void printPath(int t, int p) {
    vst[t] = 1;
    cout << t << endl;
    before = t;

    for (int n: adj[t]) {
        if (n == p) continue;
        if (vst[n]) continue;

        if (lft > 0) {
            lft--;
            printPath(n, t);
        }
    }
    if (before != t) cout << t << endl;
}



int main () {
    cin >> n >> k;

    for (int i=1; i<n; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);
    st = max_element(depth+1, depth+1+n) - depth;

    fill(depth+1, depth+1+n, 0);

    dfs(st, 0, 0);
    ed = max_element(depth+1, depth+1+n) - depth;

    getCriticalPath(st, 0);

    int radius = stk.size() -1;

    int room, edge;


    if (radius >= k) {
        cout << k+1 << endl << k << endl;

        for (int i=0; i<=k; i++) cout << stk[i] << endl;

        return 0;
    }

    if (k >= n-1) {
        room = n;
        edge = 2*(n-1) - radius;
        lft = n;
    } else {
        room = radius + (k-radius)/2 + 1;
        edge = radius + (k-radius)/2*2;
        lft = room - stk.size();
    }

    cout << room << endl << edge << endl;

    for (auto e: stk) vst[e] = 1;
    for (auto e: stk) printPath(e, 0);
}

/*
4 6
1 2
1 3
1 4
*/
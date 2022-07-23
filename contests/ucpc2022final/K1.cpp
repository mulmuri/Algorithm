#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1<<21;



int n;
int lose[SIZE];
vector<int> adj[SIZE];
int isreg



int flag = 0;
int parent[2];
int found[2];

int dfs(int t, int p) {
    vector<int> arr(adj[t].size()+1, 0);

    int lv_max = 0;

    for (int n: adj[t]) {
        if (n == p) continue;
        int ret = dfs(n, t) + 1;
        lv_max = max(lv_max, ret);
        arr[ret] = 1;
    }

    for (int i=1; i<=adj[t].size(); i++) {
        if (arr[i] == 0) {
            found[flag] = t;
            break;
        }
    }

    //cout << t <<' '<< lv_max <<' '<< child_cnt << endl;

    return lv_max;
}


/*

3
3 6
1 8
3 7
3 5
6 2
7 4

*/




int getlv(int t) {
    int ret = 0;
    for (int n: adj[t]) {
        ret = max(ret, getlv(n));
    }
    return ret+1;
}

int main() {
    cin >> n;
    int sz = (1<<n);

    int v = 0;
    for (int i=0; i<sz-2; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        lose[v]++;
    }

    for (int i=1; i<=sz; i++) if (lose[i] == 0) {
        parent[flag] = i;
        found[flag] = i;
        dfs(i, 0);
        flag++;
    }

    if (parent[0] == found[0] && parent[1] == found[1]) {
        cout << min(parent[0], parent[1]) <<' '<< max(parent[0], parent[1]) << endl;
        cout << max(parent[0], parent[1]) <<' '<< min(parent[0], parent[1]) << endl;
    } else if (parent[0] != found[0]) {
        cout << found[0] <<' '<< found[1];
    } else if (parent[1] != found[1]) {
        cout << found[1] <<' '<< found[0];
    }
}
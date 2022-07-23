#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1<<21;




int n;
int lose[SIZE];
vector<int> adj[SIZE];


int flag = 0;
int parent[2];
int found[2];

int dfs(int t) {
    int lv_max = 0;
    int child_cnt = adj[t].size();

    vector<int> arr(adj[t].size()+1);

    for (int n: adj[t]) {
        int ret = dfs(n);
        lv_max = max(lv_max, ret);
        arr[ret]++;
    }

    for (int i=0; i<child_cnt; i++) {
        if (arr[i] == 0)
    }

    if (lv_max != child_cnt) found[flag] = t;
    //cout << t <<' '<< lv_max <<' '<< child_cnt << endl;

    return lv_max;
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
        dfs(i);
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
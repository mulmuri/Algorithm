#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int SIZE = 200001;



int n;
int pt[SIZE];

int dp1[SIZE];
int dp2[SIZE];
int ans[SIZE];

int vst1[SIZE];
int vst2[SIZE];
int vst3[SIZE];

vector<pair<int,int> > adj[SIZE];


void dfs1(int t) {
    vst1[t] = 1;
    for (auto e: adj[t]) {
        int n = e.first;
        int cost = e.second;

        if (vst1[n]) continue;
        dfs1(n);

        dp1[t] = max(dp1[t], dp1[n] + cost);
    }
}

void dfs2(int t) {
    vst2[t] = 1;
    for (auto it = adj[t].end(); it != adj[t].begin(); it--) {
        int n =  (it-1)->first;
        int cost = (it-1)->second;

        if (vst2[n]) continue;
        dfs2(n);

        dp2[t] = max(dp2[t], dp2[n] + cost);
    }
}

void dfs3(int t, int p) {
    vst3[t] = 1;
    for (auto e: adj[t]) {
        int n = e.first;

        if (vst3[n]) continue;
        dfs3(n, t);

        ans[t] = (dp1[t] + dp2[p]);
    }
}


int main() {
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for (int i=1; i<=n; i++) cin >> pt[i];

    dfs1(1);
    dfs2(1);
    dfs3(1, 0);

    //for (int i=1; i<=n; i++) cout << dp1[i] << endl;
    //for (int i=1; i<=n; i++) cout << dp2[i] << endl;
    for (int i=1; i<=n; i++) cout << ans[i] << endl;
}
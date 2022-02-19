#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
#define MOD 998232453
#define INF 1e9
#define SIZE 200001

int n,q;
int arr[SIZE];
int ans[SIZE];
int vst[SIZE];
vector<pair<int,int> > query[SIZE];

vector<int> adj[SIZE];



vector<int> dfs(int t) {
    vst[t] = 1;
    vector<int> v1 = {arr[t]};
    for (auto n: adj[t]) {
        if (vst[n]) continue;

        vector<int> v2 = dfs(n);
        v1.insert(v1.end(), v2.begin(), v2.end());
    }

    sort(v1.begin(), v1.end(), greater<>());
    if (v1.size() > 20) v1.resize(20);

    for (auto e: query[t]) {
        ans[e.second] = v1[e.first-1];
    }
    return v1;
}



int main() {
    fastio;

    cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> arr[i];

    for (int i=1; i<n; i++) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i=1; i<=q; i++) {
        int v,k;
        cin >> v >> k;
        query[v].push_back({k,i});
    }

    dfs(1);

    for (int i=1; i<=q; i++) cout << ans[i] << endl;
}
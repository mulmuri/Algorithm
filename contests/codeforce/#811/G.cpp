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


int n;
int arr[SIZE];
int ans[SIZE];


vector<tuple<int,int,int>> adj[SIZE];
vector<int> path;


void dfs(int t, int len) {
    for (auto [n, a, b]: adj[t]) {
        path.push_back(path.back() + b);
        dfs(n, len+a);
        path.pop_back();
    }

    ans[t] = upper_bound(path.begin(), path.end(), len) - path.begin() - 1;
}


void solve() {
    cin >> n;
    path.clear();
    path = {0};
    fill(ans, ans+n+1, 0);

    for (int i=1; i<=n; i++) adj[i].clear();

    for (int i=2; i<=n; i++) {
        int p,a,b;
        cin >> p >> a >> b;
        adj[p].push_back({i, a, b});
    }

    dfs(1, 0);

    for (int i=2; i<=n; i++) cout << ans[i] <<' '; cout << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
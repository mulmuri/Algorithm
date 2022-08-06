#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 300001;


int n;
int arr[SIZE];

vector<int> adj[SIZE];
int vst[SIZE];
int stk[SIZE];


bool dfs(int t) {
    if (stk[t]) return 1;
    stk[t] = 1;
    for (int n: adj[t]) {
        if (vst[n]) continue;
        if (dfs(n)) return 1;
    }
    stk[t] = 0;
    return 0;
}


void solve(int tc) {
    cin >> n;

    for (int i=0; i<n; i++) cin >> arr[i];

}

int32_t main() {
    fastio;

    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
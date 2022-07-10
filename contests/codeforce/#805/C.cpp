#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
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


int n,q;
int arr[SIZE];

map<int,int> idx_left;
map<int,int> idx_right;


void solve() {
    cin >> n >> q;
    map<int,int> idx_left;
    map<int,int> idx_right;

    for (int i=1; i<=n; i++) cin >> arr[i];

    for (int i=1; i<=n; i++) {
        int v = arr[i];
        if (!idx_left[v]) idx_left[v] = i;
    }
    for (int i=n; i>=1; i--) {
        int v = arr[i];
        if (!idx_right[v]) idx_right[v] = i;
    }

    while (q--) {
        int u,v; cin >> u >> v;
        cout << ((idx_left[u] && idx_right[v] && idx_left[u] <= idx_right[v]) ? "YES" : "NO") << endl;
    }
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
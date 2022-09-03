#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200001;


int n,m;
int a[SIZE];
int b[SIZE];

vector<pair<int,int>> ans;


void solve() {
    ans.clear();

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        if ((a[i] - a[j]) * (b[i] - b[j]) < 0) {
            cout << -1 << endl;
            return;
        }
    }
    
    for (int i=n-1; i; i--) for (int j=0; j<i; j++) {
        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            ans.push_back({i,j});
        }
    }

    cout << ans.size() << endl;
    for (auto[i,j]: ans) cout << i <<' '<< j << endl;

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
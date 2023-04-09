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
const int SIZE = 300001;


int n,m,r1,r2,c1,c2;


void solve() {
    cin >> n >> m >> r1 >> c1 >> r2 >> c2;

    int a = 4;
    if (r1 == 1 || r1 == n) a--;
    if (c1 == 1 || c1 == m) a--;

    int b = 4;
    if (r2 == 1 || r2 == n) b--;
    if (c2 == 1 || c2 == m) b--;

    cout << min(a,b) << endl;

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
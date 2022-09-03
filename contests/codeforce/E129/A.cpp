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


void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    cin >> m;
    for (int i=0; i<m; i++) cin >> b[i];
    
    int maxn = *max_element(a, a+n);
    int maxm = *max_element(b, b+m);

    if (maxn > maxm) cout << "Alice" << endl << "Alice" << endl;
    else if (maxn < maxm) cout << "Bob" << endl << "Bob" << endl;
    else cout << "Alice" << endl << "Bob" << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
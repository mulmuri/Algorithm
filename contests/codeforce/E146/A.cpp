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


int a,b;


void solve() {
    cin >> a >> b;
    if (a%2 == 1 && b%2 == 0) cout << "NO" << endl;
    else cout << "YES "<< endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
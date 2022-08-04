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


int n;
int arr[SIZE];


void solve() {
    cin >> n;
    if (n == 1) cout << 2 << endl;
    else cout << (n-1)/3+1 << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
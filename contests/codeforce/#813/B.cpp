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
    if (n%2 == 1) {
        cout << 1 <<' ';
        for (int i=2; i<=n; i+=2) cout << i+1 <<' '<< i <<' ';
    } else {
        for (int i=1; i<=n; i+=2) cout << i+1 <<' '<< i <<' ';
    }
    cout << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
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
const int SIZE = 1001;


int n,k;
int arr[SIZE][SIZE];


void solve() {
    cin >> n >> k;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin >> arr[i][j];

    int cnt = 0;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        if (arr[i][j] != arr[n-1-i][n-1-j]) cnt++;
    }
    cnt /= 2;

    if (n%2 == 0) {
        if (cnt <= k && (cnt-k)%2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else {
        if (cnt <= k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }



}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
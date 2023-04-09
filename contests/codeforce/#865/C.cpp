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


int n;
int arr[SIZE];



void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    if (n%2 == 1) {
        cout << "YES" << endl;
        return;
    }

    int asum = 0;
    int bsum = 0;

    for (int i=0; i<n; i++) {
        if (i%2 == 0) asum += arr[i];
        else bsum += arr[i];
    }

    if (asum <= bsum) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
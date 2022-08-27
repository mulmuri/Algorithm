#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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


int n,q;
int arr[SIZE];
int atop[SIZE];


void solve() {
    cin >> n >> q;
    fill(atop, atop+n+1, 0);
    for (int i=1; i<=n; i++) cin >> arr[i];

    int now = 0;
    for (int i=1; i<=n; i++) {
        if (arr[now] < arr[i]) {
            atop[now] = i;
            now = i;
        }
    }

    auto top = max_element(arr, arr+n+1);
    int top_idx = top - arr;
    int top_v = *top;

    while (q--) {
        int i,k; cin >> i >> k;

        if (i == top_idx) {
            if (i == 1) cout << max(k - i + 1, (int)0) << endl;
            else cout << max(k - i + 2, (int)0) << endl;
        } else {
            if (i == 1) cout << max(min(atop[i]-1, k+1) - i, (int)0) << endl;
            else cout << max(min(atop[i]-1, k+2) - i, (int)0) << endl;            
        }
    }
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
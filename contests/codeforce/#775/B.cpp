#include <bits/stdc++.h>
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


int n;
int arr[SIZE];


void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    int a = *max_element(arr, arr+n);
    int b = accumulate(arr, arr+n, (int)0) - a;

    if (a == 0) {
        cout << 0 << endl;
        return;
    }

    cout << 1 + max((int)0, a - b - 1) << endl;

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
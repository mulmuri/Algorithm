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
    for (int i=1; i<=n; i++) arr[i] = i;
    cout << n << endl;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) cout << arr[j] <<' '; cout << endl;
        swap(arr[i], arr[i+1]);
    }
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
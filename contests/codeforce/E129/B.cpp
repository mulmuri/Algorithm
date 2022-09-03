#include <bits/stdc++.h>
#include <iostream>
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
int arr[SIZE];
int b[SIZE];


void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    cin >> m;
    for (int i=0; i<m; i++) cin >> b[i];

    int target = accumulate(b, b+m, (int)0) % n;
    cout << arr[target+1] << endl;

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
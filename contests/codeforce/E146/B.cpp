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


int a,b;


void solve() {
    cin >> a >> b;

    int mid = sqrt(a+b-2);
    int minv = a+b;

    for (int i=max(mid-1000, (int)1); i<=mid+1000; i++) {
        int v = (a-1)/i + (b-1)/i + 1 + i;
        minv = min(minv, v);
    }

    cout << minv << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
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
int square[SIZE];


void f(int v) {
    if (v == 0) return;
    if (v == 1) {
        cout << 0 <<' ';
        return;
    }
    if (v == 2) {
        cout << 1 <<' '<< 0 <<' ';
        return;
    }

    int s = 1;
    while (v > s*s+1) s++;
    s = s*s;
    f(s - v + 1);

    for (int i=v-1; i>s-v; i--) cout << i <<' ';
}


void solve() {
    cin >> n;
    f(n);
    cout << endl;
}

int32_t main() {
    fastio;

    for (int i=1; i*i<SIZE-1; i++) square[i*i+1] = 1;

    int t; cin >> t;
    while (t--) solve();
}
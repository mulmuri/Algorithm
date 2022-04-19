#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 200001;

int n,m;
int arr[SIZE];


void solve() {
    cin >> n >> m;

    if (n == 1 && m == 1) {
        cout << 0 << endl;
        return;
    }
    if (n == 1) {
        if (m == 2) cout << 1 << endl;
        else cout << -1 << endl;
        return;
    }
    if (m == 1) {
        if (n == 2) cout << 1 << endl;
        else cout << -1 << endl;
        return;
    }

    int a = (min(n, m) - 1) * 2;
    int r = max(n, m) - min(n, m);
    if (r%2 == 0) {
        cout << a + r*2 << endl;
    } else {
        cout << a + r*2 - 1 << endl;
    }
}

int main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
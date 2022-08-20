#include <iostream>
#include <vector>
#include <string>
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


void solve() {
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << 0 << endl;
        return;
    }
    if (n == 1 || m == 1) {
        cout << n + m - 1 << endl;
        return;
    }
    cout << m + n - 2 + min(n,m) << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
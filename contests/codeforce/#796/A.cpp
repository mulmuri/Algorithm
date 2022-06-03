#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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


int x;

void solve() {
    cin >> x;

    if ((x == 1) || (x == 2)) {
        cout << 3 << endl;
        return;
    }

    int i = 1;
    while ((x & i) == 0) i <<= 1;

    if ((x == i)) cout << i+1;
    else cout << i;
    cout << endl;
}

int32_t main() {
    fastio;


    int t; cin >> t;
    while (t--) solve();
}
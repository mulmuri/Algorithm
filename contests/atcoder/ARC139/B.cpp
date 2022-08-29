#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 300001;


int n,a,b,x,y,z;

void solve() {
    cin >> n >> a >> b >> x >> y >> z;

    int va = y - x*a;
    int vb = z - x*b;

    if (va >= 0 && vb >= 0) {
        cout << x * n << endl;
        return;
    }

    if (va >= 0) {

    }

    if (vb >= 0) {

    }

}

int32_t main() {
    fastio;
    
    int t; cin >> t;
    while (t--) solve();

}
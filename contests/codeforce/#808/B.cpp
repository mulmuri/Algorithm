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


int gcd(int a, int b) {
    while (b != 0) {
    	int r = a % b;
        a = b;
        b = r;
    }
    return a;
}


int n,l,r;
int arr[SIZE];


void solve() {
    cin >> n >> l >> r;

    for (int i=1; i<=n; i++) {
        int val;
        if (l%i == 0) val = l;
        else val = l + i - l%i;
        if (val > r) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (int i=1; i<=n; i++) {
        if (l%i == 0) cout << l <<' ';
        else cout <<( l + i - l%i) <<' ';
    }
    cout << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
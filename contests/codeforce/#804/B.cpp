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
const int SIZE = 1001;


int n,m;
int arr[SIZE][SIZE];


void solve() {
    cin >> n >> m;

    if (n == 2 && m == 2) {
        cout << 0 <<' '<< 1 << endl;
        cout << 1 <<' '<< 0 << endl;
        return;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << ((i+1)/2 + (j+1)/2)%2 <<' ';
        }
        cout << endl;
    }

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
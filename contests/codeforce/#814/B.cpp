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


int n,k;
int arr[SIZE];


void solve() {
    cin >> n >> k;

    if (k%2 == 1) {
        cout << "YES" << endl;
        for (int i=1; i<=n; i+=2) {
            cout << i <<' '<< i+1 << endl;
        }
        return;
    }

    if (k%4 == 2 && n%4 == 2) {
        cout << "YES" << endl;
        for (int i=1; i<=n-4; i+=4) {
            cout << i <<' '<< i+3 << endl;
            cout << i+1 <<' '<< i+2 << endl;
        }
        if (n%4 == 2) cout << n <<' '<< n-1 << endl;
        return;
    }

    if (k%4 == 2 && n%4 == 0) {
        cout << "YES" << endl;
        for (int i=1; i<=n; i+=4) {
            cout << i <<' '<< i+3 << endl;
            cout << i+1 <<' '<< i+2 << endl;
        }
        return;
    }


    cout << "NO" << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long
#define endl '\n'
#define SIZE 200001

int n;

void solve() {
    cin >> n;
    if (n > 19) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        int r = 0;
        for (int i=1; i<=n; i++) {
            r = r*3+1;
            cout << r <<' ';
        }
        cout << endl;
    }
}

int32_t main() {

    int t; cin >> t;
    while (t--) solve();
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
#define SIZE 200001


int n;
int arr[SIZE];

void solve() {
    cin >> n;
    if (n == 3) {
        cout << "3 2 1" << endl;
        cout << "1 3 2" << endl;
        cout << "3 1 2" << endl;        
    } else {
        for (int i=1; i<=n; i++) {
            for (int j=0; j<n; j++) {
                int v = (i+n-j)%n;
                if (v == 0) cout << n <<' ';
                else cout << v <<' ';
            }
            cout << endl;
        }
    }
}


int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
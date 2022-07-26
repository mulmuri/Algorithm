#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

typedef long long ll;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 1000001;


int n,c;
int arr[SIZE];
int idx[SIZE];


void solve() {
    cin >> n >> c;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        idx[arr[i]] = 1;
    }
    if (idx[1] == 0) {
        for (int k=0; k<n; k++) idx[arr[k]] = 0;        
        cout << "No" << endl;
        return;
    }

    for (int i=0; i<n; i++) {
        for (int j=1; j<=arr[i]/j; j++) {
            if ((idx[j] ^ idx[arr[i]/j])) {
                cout << "No" << endl;
                for (int k=0; k<n; k++) idx[arr[k]] = 0;        
                return;
            }
        }
    }
    for (int k=0; k<n; k++) idx[arr[k]] = 0;        
    cout << "Yes" << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
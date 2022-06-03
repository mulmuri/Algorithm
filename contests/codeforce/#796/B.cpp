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


int n;
int arr[SIZE];


void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];

    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (arr[i]%2 == 1) cnt++;
    }
    if (cnt != 0) {
        cout << n - cnt << endl;
        return;
    }

    int m = 100;
    for (int i=1; i<=n; i++) {
        int j = 1, k = 0;
        while ((arr[i] & j) == 0) {
            j <<= 1;
            k++;
        }
        m = min(m, k);
    }

    cout << m + n-1 << endl;

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
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
    fill(arr, arr+n, 0);
    for (int i=1; i<=n; i++) cin >> arr[i];

    int sum = 0;
    for (int i=1; i<n; i++) sum += arr[i];

    int st = n;
    for (int i=1; i<=n; i++) {
        if (arr[i] != 0) {
            st = i;
            break;
        }
    }

    int cnt = 0;
    for (int i=st; i<=n-1; i++) {
        if (arr[i] == 0) cnt++;
    }
    cout << sum + cnt << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
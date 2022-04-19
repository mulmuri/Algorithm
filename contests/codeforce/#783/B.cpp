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
const int INF = 1e9;
const int SIZE = 200001;



int n,m;
int arr[SIZE];

void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    arr[0] = arr[n-1];

    int sum = n;
    for (int i=0; i<n; i++) sum += arr[i];
    if (sum <= m) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
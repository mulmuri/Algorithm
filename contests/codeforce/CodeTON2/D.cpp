#include <bits/stdc++.h>
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


int n,m;
int arr[SIZE];


void solve() {
    cin >> n >> m;
    for (int i=1; i<=m; i++) cin >> arr[i];

    int sum = accumulate(arr+1, arr+1+m, (int)0);
    cout << sum % m << endl;
    int avg = sum / m;
    cout << sum <<' '<< avg << endl;

    for (int i=1; i<m; i++) {
        int dif = arr[i] - avg;
        arr[i] -= dif;
        arr[i+1] += dif;
        for (int i=1; i<=m; i++) cout << arr[i] <<' '; cout << endl;
    }
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
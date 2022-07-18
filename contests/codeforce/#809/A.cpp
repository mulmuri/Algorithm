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


int n,m;
int arr[SIZE];


void solve() {
    cin >> n >> m;
    fill(arr, arr+m+1, 0);
    for (int i=1; i<=n; i++) {
        int t; cin >> t;
        if (arr[min(t, 1+m-t)] == 0) arr[min(t, 1+m-t)] = 1;
        else arr[max(t, 1+m-t)] = 1;
    }
    for (int i=1; i<=m; i++) cout << ((arr[i]) ? 'A' : 'B');
    cout << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
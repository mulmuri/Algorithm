#include <bits/stdc++.h>
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


int n;
int arr[SIZE];
int falsed[SIZE];
int used[SIZE];

vector<int> stk;


void solve() {

    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];

    fill(falsed, falsed+n+1, 0);
    fill(used, used+n+1, 0);

    for (int i=1; i<=n; i++) {
        int v = arr[i];
        if (!falsed[v] && used[v] && arr[i-1] != v) falsed[v] = 1;
        if (arr[i-1] > v) falsed[arr[i-1]] = 1;
        used[arr[i]] = 1;
    }

    int last = 0;
    for (int i=n; i; i--) {
        if (falsed[arr[i]]) {
            last = i;
            break;
        }
    }
    for (int i=1; i<=last; i++) falsed[arr[i]] = 1;

    int cnt = 0;
    for (int i=1; i<=n; i++) if (falsed[i]) cnt++;

    cout << cnt << endl;
    //for (int i=1; i<=n; i++) cout << falsed[i] <<' '; cout << endl;

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
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


int n;
int arr[SIZE];
int pf[SIZE];


void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    int flag = 1;
    for (int i=1; i<=n; i++) pf[i] = pf[i-1] + arr[i];
    for (int i=1; i<n; i++) if (pf[i] == 0 && pf[i+1] > 0) flag = 0;
    int e = *min_element(pf+1, pf+n);
    if (pf[n] == 0 && flag && e >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
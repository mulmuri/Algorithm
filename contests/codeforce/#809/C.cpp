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
const int SIZE = 200010;


int n;
int arr[SIZE];
int dp[SIZE];


void solve() {
    cin >> n;
    fill(dp, dp+n+3, 0);
    for (int i=1; i<=n; i++) cin >> arr[i];

    int cnt, ans = INF;
    if (n%2 == 1) {
        cnt = 0;
        for (int i=2; i<=n; i+=2) cnt += max(max(arr[i-1], arr[i+1])+1-arr[i], (int)0);
        ans = cnt;
    } else {
        for (int i=2; i<n-1; i+=2) dp[i] = dp[i-2] + max(max(arr[i-1], arr[i+1])+1-arr[i], (int)0);
        for (int i=n-1; i>2; i-=2) dp[i] = dp[i+2] + max(max(arr[i-1], arr[i+1])+1-arr[i], (int)0);
        for (int i=0; i<n-1; i+=2) ans = min(ans, dp[i] + dp[i+3]);
    }
    //for (int i=1; i<=n; i++) cout << dpl[i] <<' '; cout << endl;
    //for (int i=1; i<=n; i++) cout << dpr[i] <<' '; cout << endl;
    cout << ans << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
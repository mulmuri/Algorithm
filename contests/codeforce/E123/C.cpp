#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
#define SIZE 5001


int n,x;
int arr[SIZE];
int dp[SIZE][SIZE];
int ans[SIZE];

void solve() {

    cin >> n >> x;
    for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) dp[i][j] = 0;
    fill(ans, ans+n+1, 0);
    
    for (int i=1; i<=n; i++) cin >> arr[i];

    for (int i=1; i<=n; i++) {
        dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]);
        if (dp[i][0] < 0) dp[i][0] = 0;
    }


    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            dp[i][j] = max(dp[i-1][j] + arr[i], arr[i]);
            if (dp[i][j] < 0) dp[i][j] = 0;
            dp[i][j] = max(dp[i-1][j-1] + arr[i] + x, dp[i][j]);
        }
    }

    for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) ans[i] = max(ans[i], dp[j][i]);
    for (int i=1; i<=n; i++) ans[i] = max(ans[i], ans[i-1]);

    for (int i=0; i<=n; i++) cout << ans[i] <<' ';
    cout << endl;
}


int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
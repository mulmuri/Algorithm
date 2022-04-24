#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

const int SIZE = 2001;


int n, p;
int arr[SIZE][SIZE];
int val[SIZE][2];
int dp[SIZE][2];

void solve(int tc) {
    int ans = 0;

    cin >> n >> p;
    for (int i=1; i<=n; i++) for (int j=0; j<p; j++) cin >> arr[i][j];

    for (int i=1; i<=n; i++) {
        sort(arr[i], arr[i]+p);
        val[i][0] = arr[i][0];
        val[i][1] = arr[i][p-1];
    }
    
    for (int i=1; i<=n; i++) {
        dp[i][0] = min(dp[i-1][0] + abs(val[i-1][0] - val[i][1]), dp[i-1][1] + abs(val[i-1][1] - val[i][1])) + val[i][1] - val[i][0];
        dp[i][1] = min(dp[i-1][0] + abs(val[i-1][0] - val[i][0]), dp[i-1][1] + abs(val[i-1][1] - val[i][0])) + val[i][1] - val[i][0];
    }

    ans = min(dp[n][0], dp[n][1]);

    cout << "Case #"<< tc << ": " << ans << endl;
}

int32_t main() {
    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
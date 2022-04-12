#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define int long long
typedef long long ll;

#define INF 2e9
#define MOD 998244353
#define SIZE 5001

pair<int,int> arr[SIZE];
int n;

int A[SIZE];
int B[SIZE];

int dp[SIZE][SIZE];

int32_t main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> A[i];
    for (int i=0; i<n; i++) cin >> B[i];

    for (int i=0; i<n; i++) arr[i] = {A[i], B[i]};
    sort(arr, arr+n);

    int ans = 0;

    dp[0][0] = dp[0][arr[0].second] = 1;
    if (arr[0].second <= arr[0].first) ans++;

    for (int i=1; i<n; i++) {
        for (int j=0; j<SIZE; j++) {
            if (j >= arr[i].second)
                dp[i][j] += dp[i-1][j-arr[i].second];
        }
        for (int j=1; j<= arr[i].first; j++) ans += dp[i][j];
        ans %= MOD;
        for (int j=0; j<SIZE; j++) {
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= MOD;
        }
     }
     cout << ans;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
#define MOD 998244353
#define INF 1e9
#define SIZE 200001

int n;
long long x;
int arr[SIZE];
int dp[SIZE][10];

int main() {
    fastio;

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    int k = (arr[0] + arr[1])%10;
    dp[1][k]++;
    k = (arr[0] * arr[1])%10;
    dp[1][k]++;

    for (int i=2; i<n; i++) {
        for (int j=0; j<10; j++) {
            k = (j * arr[i])%10;
            dp[i][k] += dp[i-1][j];
            dp[i][k] %= MOD;

            k = (j + arr[i])%10;
            dp[i][k] += dp[i-1][j];
            dp[i][k] %= MOD;
        }
    }

    for (int i=0; i<10; i++) cout << dp[n-1][i] << endl;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'

const int MOD = 998244353;
const int INF = 1e18;
const int SIZE = 101;


int n;
int arr[SIZE];
int rem[SIZE][SIZE];
int dp[SIZE][SIZE][SIZE][SIZE];


/*
어떤 i 로 나눈 나머지에 대해
j번째 원소 확인
k개의 원소 선택
나머지가 u
*/

/*

어떤 i 로 나눈 나머지에 대해
j번째 

*/




int f(int i, int j, int k, int u) {
    if (k == -1) return 0;
    if (j == 0) return (u == 0 && k == 0);
    if (dp[i][j][k][u]) return dp[i][j][k][u];

    while (u < 0) u += i;
    return dp[i][j][k][u] = f(i, j-1, k, u) + f(i, j-1, k-1, u - rem[i][j]) % MOD;
}



int32_t main() {
    fastio;
    
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            rem[i][j] = arr[j]%i;
        }
    }

    for (int i=1; i<=n; i++) f(i, n, i, 0);



    for (int i=1; i<=n; i++) dp[i][0][0][0] = 1;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=0; k<=min(i, j); k++) {
                for (int u=0; u<i; u++) {
                    if (k == 0) {
                        dp[i][j][0][u] = dp[i][j-1][k][u];
                        continue;
                    }

                    int r = (u - rem[i][k]) % i;
                    while (r < 0) r += i;
                    if (k == 0)
                    dp[i][j][k][u] = (dp[i][j-1][k-1][r] + dp[i][j-1][k][u]) % MOD;
                }
            }
        }
    }


    int ans = 0;
    for (int i=1; i<=n; i++) {
        //cout << dp[i][n][i][0] << endl;
        ans += dp[i][n][i][0];
        ans %= MOD;
    }
    cout << ans;
}
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
#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE =101;


int n;
int dp[SIZE][SIZE];

int32_t main() {
    fastio;
    
    cin >> n;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            if (j == 1 || j == i) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            cout << dp[i][j] <<' ';
        }
        cout << endl;
    }

}
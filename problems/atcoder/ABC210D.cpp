#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define MOD 998232453
#define INF 1e16
#define SIZE 1002



int h,w,t;
long long arr[SIZE][SIZE];
long long dp[SIZE][SIZE][4];


int main() {
    fastio;
    
    cin >> h >> w >> t;

    fill(arr[0], arr[SIZE], INF);
    fill(dp[0][0], dp[SIZE][0], INF);

    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            cin >> arr[i][j];
        }
    }


    for (int i=1; i<=h; i++) for (int j=1; j<=w; j++) {
        long long r = min(dp[i-1][j][0], arr[i-1][j]);
        long long c = min(dp[i][j-1][0], arr[i][j-1]);
        dp[i][j][0] = min(r,c) + t;
    }

    for (int i=1; i<=h; i++) for (int j=w; j>=1; j--) {
        long long r = min(dp[i-1][j][1], arr[i-1][j]);
        long long c = min(dp[i][j+1][1], arr[i][j+1]);
        dp[i][j][1] = min(r,c) + t;
    }

    long long ans = INF;
    for (int i=1; i<=h; i++) for (int j=1; j<=w; j++) {
        sort(dp[i][j], dp[i][j+1]);
        ans = min(ans, dp[i][j][0] + arr[i][j]);
    }

    

    cout << ans;
}
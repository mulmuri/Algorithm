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
const int SIZE = 20001;


int n;
int arr[SIZE][2];
int arr1[SIZE][2];
int arr2[SIZE][2];
int from[SIZE][2];
int dp[SIZE];

int v[SIZE][2];


void solve() {
    cin >> n;

    int ans = INF;
    
    for (int t=0; t<2; t++) for (int i=0; i<n; i++) cin >> arr[i][t];
    for (int t=0; t<2; t++) for (int i=0; i<n; i++) {
        if (t == 0) {
            arr1[i][t] = arr1[i][t] - i;
            arr2[i][t] = arr2[i][t] + i;
        } else {
            arr1[i][t] = arr1[i][t] + i;
            arr2[i][t] = arr2[i][t] - i;
        }
    }

    int cr = 0, cc = 0;
    for (int i=1; i<n*2; i++) {
        int r = (i+1)/2%2;
        int c = i/2;

        from[c][r] = max(arr[c][r], from[cc][cr]) + 1;
        cr = r, cc = c;
    }

    for (int t=0; t<2; t++) {
        for (int i=0; i<n; i++) cout << from[i][t] <<' '; cout << endl;
    }

    for (int i=n-1; i>=0; i--) {
        int j = i%2;
        if (j == 0) {
            dp[i] = max(arr[i][0]+1, arr[i][1]) + 1;
            ans = min(ans, max(dp[i], from[i-1][j] + 2));
        }
    }

}

int32_t main() {
    fastio;

    //int t; cin >> t;
    //while (t--) solve();
    solve();
}
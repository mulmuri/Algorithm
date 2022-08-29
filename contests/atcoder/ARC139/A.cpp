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
const int SIZE = 300001;


int n;
int arr[SIZE];
int pmax[SIZE];
int dp[SIZE];


/*
1 << a

1 << a + 1 << a


*/

int32_t main() {
    fastio;
    
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    for (int i=1; i<=n; i++) pmax[i] = max(arr[i], pmax[i-1]);

    int val = 0;
    for (int i=1; i<=n; i++) {
        int v = ((int)1 << arr[i]);
        if (arr[i] < pmax[i]) dp[i] = dp[i-1] + v;
    }
    //for (int i=1; i<=n; i++) cout << dp[i] <<' '; cout << endl;
    cout << dp[n];
}
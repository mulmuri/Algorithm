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

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE_N = 1001;
const int SIZE_S = 101;


int n;
int arr[SIZE_N];

int false_dp[SIZE_N][SIZE_N][SIZE_S];
int dp[SIZE_N][SIZE_N][SIZE_S];



int f(int l, int r, int u) {
    if (dp[l][r][u] > 0) cout << l <<' '<< r <<' '<< u << ' '<< dp[l][r][u] << endl;
    if (dp[l][r][u]) return dp[l][r][u];
    if (l == r) return -INF;

    int newl = (l+n+1)%n;
    int newr = (r+n-1)%n;

    int ret = 0;
    ret = max(ret, f(newl, r, u - arr[l]));
    ret = max(ret, f(l, newr, u - arr[r]));
    ret = max(ret, f(newl, r, u + arr[l]) + arr[l]);
    ret = max(ret, f(l, newr, u + arr[r]) + arr[r]);

    return ret;


/*
    int _min = INF;


    int _max = -INF;
    if (u + arr[l] < 0) _min = min(_min, f(newl, r, u + arr[l]));
    if (u + arr[r] < 0) _min = min(_min, f(l, newr, u + arr[r]));

    if (u - arr[l] >= 0) _max = max(_max, f(newl, r, u - arr[l]) + arr[l]);
    if (u - arr[r] >= 0) _max = max(_max, f(l, newr, u - arr[r]) + arr[r]);

    if (_min == INF) return _max;
    return dp[l][r][u] = (u >= 0) ? max(_min, _max) : min(_min, _max);
*/
}


int32_t main() {
    fastio;

    int ar[3] = {1,2,3};

    int a = max_element(ar, ar+3);

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    for (int i=0; i<n; i++) dp[i][i][-arr[i]] = arr[i];

    int ans = 0;
    for (int i=0; i<n; i++) for (int j=1-SIZE_S; j<SIZE_S; j++) ans = max(ans, f(i, (i+n-1)%n, j));
    cout << ans;
}
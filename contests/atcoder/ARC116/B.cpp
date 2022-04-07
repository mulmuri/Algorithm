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
#define int long long

const int MOD = 998244353;
const int INF = 1e9;
const int SIZE = 300001;



int n;
int arr[SIZE];

int32_t main() {
    fastio;
    
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    sort(arr+1, arr+1+n);

    int ans = 0;
    int tmp = 0;
    for (int i=2; i<=n; i++) {
        tmp *= 2;
        tmp += arr[i-1];
        tmp %= MOD;
        ans += tmp*arr[i];
        ans %= MOD;
    }

    for (int i=1; i<=n; i++) {
        ans += arr[i]*arr[i];
        ans %= MOD;
    }

    cout << ans;
}
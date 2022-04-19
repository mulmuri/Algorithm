#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200001;

int n;
int arr[SIZE];





void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];

    int cur = 0, cnt;
    int ans =  INF;
    for (int i=1; i<=n; i++) {
        cnt = 0;

        cur = 0;        
        for (int j=i-1; j; j--) {
            int k = cur/arr[j] + 1;
            cnt += k;
            cur = k*arr[j];
        //    cout << j <<' '<< k << endl;
        }
        cur = 0;
        for (int j=i+1; j<=n; j++) {
            int k = cur/arr[j] + 1;
            cnt += k;
            cur = k*arr[j];
        //    cout << j <<' '<< k << endl;
        }

        ans = min(ans, cnt);
    }

    cout << ans;
}

int32_t main() {
    fastio;

    solve();
}
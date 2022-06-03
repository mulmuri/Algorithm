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

typedef long long ll;
typedef pair<int,int> pii;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200001;


int n,k;
int arr[SIZE];
int pf[SIZE];


void solve() {
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> arr[i];
    int ans;
    int sum = 0;

    if (k >= n) {
        for (int i=1; i<=n; i++) sum += arr[i];
        ans = sum + n*(n+1)/2 + n*(k-n-1);
    } else {
        int psum = 0;
        for (int i=1; i<=k; i++) psum += arr[i];
        sum = psum;
        for (int i=k+1; i<=n; i++) {
            psum += arr[i];
            psum -= arr[i-k];
            sum = max(sum, psum);
        }

        ans = sum + k*(k-1)/2;
    }
    cout << ans << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
/*
6 2 2 8 2 4 9 11

34

5 6 1 2 3
7 8 3 4 5
7 9 5 7 9
*/



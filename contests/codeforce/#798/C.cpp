#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

typedef long long ll;

const int MOD = 998232453;
const int SIZE = 5001;


int n;
int arr[SIZE];
int rarr[SIZE];

int sorted[SIZE][SIZE];
int rsorted[SIZE][SIZE];


void queryl(int idx, int val) {

}


void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    for (int i=0; i<n; i++) rarr[i] = arr[n-1-i];

    for (int i=0; i<n; i++) {
        copy(arr, arr+i, sorted[i]);
        sort(sorted[i], sorted[i]+i);

        copy(rarr, rarr+i, rsorted[i]);
        sort(rsorted[i], rsorted[i]+i);
    }


    ll ans = 0;

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            int ni = n-1-j;

            ll l = lower_bound(sorted[i], sorted[i]+i, arr[j]) - sorted[i];
            ll r = lower_bound(rsorted[ni], rsorted[ni]+ni, arr[i]) - rsorted[ni];
            ans += l*r;
        }
    }
    
    cout << ans << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;
#define int long long
#define endl '\n'
#define SIZE 200001
#define INF 2e9


int n;
int a[SIZE];
int b[SIZE];
int al[SIZE];
int ar[SIZE];
int bl[SIZE];
int br[SIZE];

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    for (int i=0; i<n; i++) al[i] = abs(a[0] - b[i]);
    for (int i=0; i<n; i++) ar[i] = abs(a[n-1] - b[i]);

    for (int i=0; i<n; i++) bl[i] = abs(b[0] - a[i]);
    for (int i=0; i<n; i++) br[i] = abs(b[n-1] - a[i]);

    sort(al, al+n);
    sort(ar, ar+n);
    sort(bl, bl+n);
    sort(br, br+n);

    int ans = INF;

    ans = min(ans, abs(a[0] - b[0]) + abs(a[n-1] - b[n-1]));
    ans = min(ans, abs(a[0] - b[n-1]) + abs(a[n-1] - b[0]));
    ans = min(ans, abs(a[0] - b[0]) + ar[0] + br[0]);
    ans = min(ans, abs(a[n-1] - b[n-1]) + al[0] + bl[0]);
    ans = min(ans, abs(a[0] - b[n-1]) + ar[0] + bl[0]);
    ans = min(ans, abs(a[n-1] - b[0]) + al[0] + br[0]);
    ans = min(ans, al[0] + ar[0] + bl[0] + br[0]);

    cout << ans << endl;


}


int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
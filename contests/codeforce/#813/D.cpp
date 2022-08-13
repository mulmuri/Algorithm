#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 200001;


int n,k;
int arr[SIZE];

pair<int,int> p[SIZE];


void solve() {
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> arr[i];

    if (k == n) {
        cout << INF << endl;
        return;
    }
    
    if (n == 2) {
        sort(arr, arr+n);
        if (k == 0) cout << arr[0] << endl;
        else if (k == 1) cout << arr[1] << endl;
        return;
    }

    if (k == 0) {
        int minv = *min_element(arr, arr+n);
        int w = 0;
        for (int i=1; i<n; i++) w = max(w, min(arr[i-1], arr[i]));
        cout << min(minv*2, w) << endl;
        return;
    }

    if (k == 1) {
        int ans = 0;
        int min1 = min_element(arr, arr+n) - arr;
        int tmp = arr[min1];
        arr[min1] = INF;
        int min2 = min_element(arr, arr+n) - arr;

        int w = 0;
        for (int i=1; i<n; i++) w = max(w, min(arr[i-1], arr[i]));
        ans = min(w, arr[min2]*2);

        arr[min1] = tmp;
        arr[min2] = INF;

        w = 0;
        for (int i=1; i<n; i++) w = max(w, min(arr[i-1], arr[i]));
        ans = max(ans, min(w, arr[min1]*2));

        cout << ans << endl;
        return;
    }


    for (int i=0; i<n; i++) p[i] = {arr[i], i};
    sort(p, p+n);

    for (int i=0; i<k; i++) {
        auto[v, idx] = p[i];
        arr[idx] = INF;
    }

    int w = 0;
    for (int i=1; i<n; i++) w = max(w, min(arr[i-1], arr[i]));
    cout << max(min(w, 2*p[k].first), 2*p[k-1].first) << endl;

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
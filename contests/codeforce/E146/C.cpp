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
const int SIZE = 200001;


int n, s1, s2;
pair<int,int> arr[SIZE];


void solve() {
    cin >> n >> s1 >> s2;
    for (int i=0; i<n; i++) {
        int c; cin >> c;
        arr[i] = {c, i+1};
    }
    sort(arr, arr+n);
    reverse(arr, arr+n);

    vector<int> v1, v2;

    int t1 = s1;
    int t2 = s2;
    for (int i=0; i<n; i++) {
        if (t1 < t2) {
            t1 += s1;
            v1.push_back(arr[i].second);
        } else {
            t2 += s2;
            v2.push_back(arr[i].second);
        }
    }

    cout << v1.size() <<' ';
    for (int e: v1) cout << e <<' '; cout << endl;
    cout << v2.size() <<' ';
    for (int e: v2) cout << e <<' '; cout << endl;

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
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

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 300001;



int n;
int arr[4];

inline int abs(int x, int y) {return (x > y) ? x : y;};

void solve() {
    cin >> arr[0] >> arr[1] >> arr[2];
    arr[3] = arr[0];

    int ans = INF;
    for (int i=0; i<3; i++) {
        if (arr[i] == arr[i+1])
            ans = min(ans, arr[i]);
        if (abs(arr[i] - arr[i+1])%3 == 0)
            ans = min(ans, max(arr[i], arr[i+1]));
    }

    cout << ((ans == INF) ? -1 : ans) << endl;
}


int32_t main() {
    fastio;
    
    int t; cin >> t;
    while (t--) solve();
}
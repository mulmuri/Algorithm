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
typedef long long ll;

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 300001;




int n,x,y;
ll arr[SIZE];

int32_t main() {
    fastio;
    
    cin >> n >> x >> y;

    for (int i=1; i<=n; i++) cin >> arr[i];


    ll ans = 0;

    int max_idx = 0, min_idx = 0;
    int x_idx = 0, y_idx = 0;

    for (int i=1; i<=n; i++) {
        if (arr[i] > x) max_idx = i;
        else if (arr[i] == x) x_idx = i;
        if (arr[i] < y) min_idx = i;
        else if (arr[i] == y) y_idx = i;

        if (x_idx > max_idx && y_idx > min_idx) {
            ans += max(0, min(x_idx, y_idx) - max(max_idx, min_idx));
        }
    }

    cout << ans;
}
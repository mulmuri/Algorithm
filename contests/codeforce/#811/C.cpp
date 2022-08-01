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
const int SIZE = 101;


int n;
int arr[SIZE];


void solve() {
    cin >> n;
    vector<int> ans;

    int target = 9;
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        cnt++;
        if (cnt == target) {
            ans.push_back(cnt);
            target--;
            cnt = 0;
        } else if (i == n) {
            ans.push_back(cnt);
        }
    }

    reverse(ans.begin(), ans.end());
    for (auto e: ans) cout << e;
    cout << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
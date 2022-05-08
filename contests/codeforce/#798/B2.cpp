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


int n;


void solve() {
    cin >> n;
    string arr; cin >> arr;

    string arr0 = '0' + arr;
    string arr1 = '1' + arr;

    int ans0 = 0, seg0 = 1;
    for (int i=2; i<=n; i+=2) {
        if (arr0[i] == arr0[i-1]) continue;
        ans0++;
        if (arr0[i-1] == arr0[i-2]) arr0[i] = (arr0[i] == '0') ? '1' : '0';
        else arr0[i-1] = (arr0[i-1] == '0') ? '1' : '0';
    }
    for (int i=2; i<=n; i++) if (arr0[i-1] != arr0[i]) seg0++;

    int ans1 = 0, seg1 = 1;
    for (int i=2; i<=n; i+=2) {
        if (arr1[i] == arr1[i-1]) continue;
        ans1++;
        if (arr1[i-1] == arr1[i-2]) arr1[i] = (arr1[i] == '0') ? '1' : '0';
        else arr1[i-1] = (arr1[i-1] == '0') ? '1' : '0';
    }
    for (int i=2; i<=n; i++) if (arr1[i-1] != arr1[i]) seg1++;

    cout << ans0 <<' '<< min(seg0, seg1) << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
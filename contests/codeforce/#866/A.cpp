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
const int SIZE = 300001;


string s;

void solve() {
    cin >> s;

    if (s == "^") {
        cout << 1 << endl;
        return;
    }

    int cnt = 0;

    string str = "_"+s+"_";
    for (int i=1; i<str.size(); i++) {
        if (str[i] == '_' && str[i-1] == '_') {
            cnt++;
        }
    }

    cout << cnt << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
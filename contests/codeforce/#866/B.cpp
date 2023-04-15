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

/*
 1111100
 0111110
 0011111
 100111
 110011



 111
 0111
 001111

 3 -> 2*2
 4 -> 3*2
 5 -> 3*3
  ->
*/


void solve() {
    cin >> s;

    string ss = s + s;

    int cnt = 0;
    int maxc = 0;

    for (char c: s) {
        if (c == '1') cnt++;
    }

    if (cnt == s.size()) {
        cout << cnt * cnt << endl;
        return;
    }

    cnt = 0;

    for (char c: ss) {
        if (c == '1') {
            cnt++;
            maxc = max(maxc, cnt);
        } else if (c == '0') {
            cnt = 0;
        }
    }

    if (maxc%2 == 1) {
        cout << (maxc+1)/2 * (maxc+1)/2 << endl;
    } else {
        cout << maxc/2 * (maxc/2 + 1) << endl;
    }
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
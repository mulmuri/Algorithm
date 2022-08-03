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
string s;


void solve() {
    cin >> n >> s;

    int cnt = n;
    for (int i=1; i<n; i++) {
        if (s[i-1] != s[i]) cnt += i;
    }
    cout << cnt << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
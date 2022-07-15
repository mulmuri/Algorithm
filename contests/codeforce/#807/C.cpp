#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
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


int n,c,q;
string s;


void solve() {
    cin >> n >> c >> q >> s;

    int len = n;
    map<int,int> target;
    vector<int> arr = {1};

    while (c--) {
        int u,v; cin >> u >> v;
        target[len+1] = u;
        arr.push_back(len+1);
        len += (v - u + 1);
    }
    //for (auto e: arr) cout << e<< ' '; cout << endl;

    while (q--) {
        int k; cin >> k;
        while (k > n) {
            int ik = *(upper_bound(arr.begin(), arr.end(), k)-1);
            k = target[ik] + (k - ik);
        }
        cout << s[k-1] << endl;
    }
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
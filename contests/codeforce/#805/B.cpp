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


string s;


void solve() {
    cin >> s;

    int ans = 1;
    vector<int> memory;
    for (auto e: s) {
        if (find(memory.begin(), memory.end(), e) == memory.end()) {
            if (memory.size() == 3) {
                memory.clear();
                ans++;
            }
            memory.push_back(e);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
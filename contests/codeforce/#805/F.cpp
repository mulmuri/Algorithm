#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
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


int n;
int b[SIZE];




void solve() {
    map<int,int> st;
    priority_queue<int> pq;

    cin >> n;
    for (int i=1; i<=n; i++) {
        int v; cin >> v;
        while (v%2 == 0) v >>= 1;
        st[v]++;
    }
    for (int i=1; i<=n; i++) cin >> b[i];
    sort(b+1, b+1+n, greater<>());

    for (int i=1; i<=n; i++) {
        while (b[i]) {
            if (st[b[i]]) {
                st[b[i]]--;
                break;
            } else {
                b[i] >>= 1;
            }
        }
        if (b[i] == 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
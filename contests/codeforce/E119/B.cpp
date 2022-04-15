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
const int INF = 1e9;
const int SIZE = 200001;



int w,h,w1, w2, h1, h2;
int x1[SIZE];
int x2[SIZE];
int y1[SIZE];
int y2[SIZE];

void solve() {
    cin >> w >> h;
    cin >> w1;
    for (int i=1; i<=w1; i++) cin >> x1[i];
    cin >> w2;
    for (int i=1; i<=w2; i++) cin >> x2[i];
    cin >> h1;
    for (int i=1; i<=h1; i++) cin >> y1[i];
    cin >> h2;
    for (int i=1; i<=h2; i++) cin >> y2[i];

    cout << max(
        max(x1[w1] - x1[1], x2[w2] - x2[1]) * h,
        max(y1[h1] - y1[1], y2[h2] - y2[1]) * w
    ) << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
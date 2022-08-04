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


int n,m;
pair<int,int> input[SIZE];




void solve() {
    vector<pair<int,int>> vec;
    vector<pair<int,int>> rain;
    vector<pair<int,int>> flood;

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int x,p; cin >> x >> p;
        vec.push_back({x - p, 1});
        vec.push_back({x, -2});
        vec.push_back({x + p, 1});
        input[i] = {x,p};
    }

    sort(vec.begin(), vec.end());

    int inclin = 0;
    int bef = vec[0].first;
    int now = 0;

    for (auto[x, a]: vec) {
        now = now + inclin * (x - bef);
        now = max(now, (int)0);
        rain.push_back({x, now});
        inclin += a;
        bef = x;
    }


    for (int i=1; i<=n; i++) {
        auto[x, p] = input[i];
        pair<int,int> u = {x, 0};

        auto[nx, lv] = *lower_bound(rain.begin(), rain.end(), u);
        flood.push_back({nx, max((int)0, lv)});
    }

    int left = INF;
    for (auto[x, p]: flood) if (p) left = min(left, x - p);
    int right = -INF;
    for (auto[x, p]: flood) if (p) right = max(right, p + x);

    if (left >= right) {
        for (int i=0; i<n; i++) cout << 1; cout << endl;
        return;
    }

    cout << endl;
    for (auto[x, p]: rain) cout << x <<' '<< p << endl; cout << endl;
    for (auto[x, p]: flood) cout << x <<' '<< p << endl;

    //cout << left <<' '<< right << endl;

    for (int i=0; i<n; i++) {
        auto[x, p] = input[i];
        int top = max(x - left, right - x);
        if (top >= p+m) cout << 1;
        else cout << 0;
    }
    cout << endl;

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
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


int n,m,k;
int sz_a, sz_b;
int a[SIZE];
int b[SIZE];

vector<pair<int,int>> pa;
vector<pair<int,int>> pb;


pair<int,int> f(int a, int d) {
    int sec = 1;
    while (a % d == 0) {
        a /= d;
        sec *= d;
    }
    return {a, sec};
}


void solve() {
    pa.clear(); pb.clear();

    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];
    cin >> k;
    for (int i=1; i<=k; i++) cin >> b[i];

    for (int i=1; i<=n; i++) {
        int p,q;
        pair<int,int> tmp = f(a[i], m);

        if (pa.size() != 0 && pa.back().first == tmp.first) {
            pa.back() = {tmp.first, pa.back().second + tmp.second};
        } else {
            pa.push_back(tmp);
        }
    }

    for (int i=1; i<=k; i++) {
        int p,q;
        pair<int,int> tmp = f(b[i], m);

        if (pb.size() != 0 && pb.back().first == tmp.first) {
            pb.back() = {tmp.first, pb.back().second + tmp.second};
        } else {
            pb.push_back(tmp);
        }
    }

    //for (auto[a,b]: pa) cout << a <<' '<< b << endl;
    //for (auto[a,b]: pb) cout << a <<' '<< b << endl;

    if (pa.size() != pb.size()) {
        cout << "No" << endl;
        return;
    }
    for (int i=0; i<pa.size(); i++) {
        if (pa[i].first != pb[i].first || pa[i].second != pb[i].second) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;


}

int32_t main() {

    fastio;

    int t; cin >> t;
    while (t--) solve();
}
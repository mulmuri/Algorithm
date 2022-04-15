#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 500001;




int pr[SIZE];

pair<int,int> query[SIZE];

int find(int x) {
    if (x == pr[x]) return x;
    return pr[x] = find(pr[x]);
}

void merge(int p, int q) {
    if (find(p) == find(q)) return;
    pr[p] = find(q);
}


void solve() {
    vector<int> v, ans;
    for (int i=1; i<SIZE; i++) pr[i] = i;

    int q; cin >> q;
    for (int i=0; i<q; i++) {
        int a,x,y;
        cin >> a;
        if (a == 1) {
            cin >> x;
            query[i] = {-1, x};
        } else {
            cin >> x >> y;
            query[i] = {x,y};
        }
    }

    for (int i=q-1; i>=0; i--) {
        if (query[i].first == -1) {
            int x = query[i].second;
            ans.push_back(pr[x]);
        } else {
            auto[x,y] = query[i];
            pr[x] = pr[y];
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto e: ans) cout << e <<' ';
}

int main() {
    fastio;
    solve();
}
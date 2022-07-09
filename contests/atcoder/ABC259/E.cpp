#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 300001;


int n,m;
vector<pair<int,int>> arr[SIZE];
map<int,int> lv;
map<int,int> ov_ckeck;



int32_t main() {
    fastio;
    
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> m;
        while (m--) {
            int p,e; cin >> p >> e;
            arr[i].push_back({p,e});

            if (e == lv[p]) ov_ckeck[p] = e;
            if (e > lv[p]) lv[p] = e;
        }
    }

    int cnt = 0;

    for (int i=1; i<=n; i++) {
        for (auto[p,e]: arr[i]) {
            if (lv[p] == e && ov_ckeck[p] != e) {
                cnt++;
                break;
            }
        }
    }

    if (cnt == n) cout << cnt;
    else cout << cnt+1;
}
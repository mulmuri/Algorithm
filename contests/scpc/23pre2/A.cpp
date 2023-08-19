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
typedef long long ll;


const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 100001;


int n,k;
int arr[SIZE];

using pos = pair<int,int>;

pair<int,pos> simulation(pos cur) {
    int pt = 0;

    for (int i=0; i<n; i++) {
        cur.second += arr[i];

        if (cur.first == 0 && cur.second == 5) {
            cur.first = 1;
            cur.second = 0;
            continue;
        }
        
        if (cur.first == 0 && cur.second == 10) {
            cur.first = 2;
            cur.second = 0;
            continue;
        }
        
        if (cur.first == 1 && cur.second == 3) {
            cur.first = 2;
            cur.second = 3;
            continue;
        }

        if (cur.first == 0 && cur.second > 20) {
            pt++;
            cur.first = 0;
            cur.second = 0;
            continue;
        }

        if (cur.first == 1 && cur.second > 11) {
            pt++;
            cur.first = 0;
            cur.second = 0;
            continue;
        }

        if (cur.first == 2 && cur.second > 6) {
            pt++;
            cur.first = 0;
            cur.second = 0;
            continue;
        }
    }

    return {pt, cur};
}



void solve(int tc) {
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> arr[i];

    map<pos, pair<int, pos>> mp;

    ll ans = 0;
    pos cur = {0,0};

    while (k--) {
        if (mp.find(cur) != mp.end()) {
            auto res = mp[cur];
            ans += res.first;
            cur = res.second;

            continue;
        }

        auto res = simulation(cur);
        mp[cur] = res;
        ans += res.first;
        cur = res.second;
    }

    cout << "Case #" << tc << endl;
    cout << ans << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
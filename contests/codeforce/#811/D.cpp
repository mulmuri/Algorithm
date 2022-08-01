#include<bits/stdc++.h>
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
const int SIZE = 11;


int n;
string target;
string str[SIZE];



void solve() {
    vector<pair<int,int>> ans;

    cin >> target >> n;
    for (int i=1; i<=n; i++) cin >> str[i];

    bool match = 1;
    int finished = 0;

    int max_num = -1;
    int max_idx = -1;

    while (match) {
        match = 0;
        max_num = finished;
        max_idx = -1;

        for (int i=1; i<=n; i++) {
            for (int rnum = min(finished + (int)str[i].size(), (int)target.size()); rnum >= finished+1; rnum--) {
                //cout << (int)str[i].size() << ' '<< finished << endl;
                //cout << i <<' '<< rnum << endl;
                if (rnum - (int)str[i].size() < 0) break;
                assert(rnum - (int)str[i].size() >= 0);

                auto target_left = target.begin() + rnum - (int)str[i].size();
                auto target_right = target.begin() + rnum;

                if (equal(str[i].begin(), str[i].end(), target_left, target_right)) {
                    match = 1;
                    if (max_num < rnum) {
                        max_num = rnum;
                        max_idx = i;
                    }
                }
            }
        }

        ans.push_back({max_idx, max_num});
        if (max_num == (int)target.size()) break;
        finished = max_num;
    }

    if (match) {
        cout << ans.size() << endl;
        for (auto[num, idx]: ans) cout << num <<' '<< idx - (int)str[num].size() + 1 << endl;        
    } else {
        cout << -1 << endl;
    }

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
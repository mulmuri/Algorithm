#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define MOD 998244353
#define INF 2e9
#define SIZE 200001



int n;

vector<int> fact = {0};
vector<int> fact2[15];


void solve() {
    cin >> n;

    int ans = INF;
    for (int i=0; i<13; i++) {
        for (auto val: fact2[i]) {
            int x = n - val;
            if (x < 0) break;

            int cnt = i;
    
            while (x) {
                if (x%2 == 1) cnt++;
                x /= 2;
            }
            ans = min(ans, cnt);
        }
    }

    cout << ans << endl;
}


int32_t main() {

    int val = 6;
    for (int i=4; val <= (long long)1e12; i++) {
        fact.push_back(val);
        val *= i;
    }

    for (int i=0; i<(1 << 13); i++) {
        int cnt = 0;
        int val = 0;

        for (int j=0; j<13; j++) {
            if ((i & (1 << j))) {
                cnt++;
                val += fact[j];
            }
        }

        fact2[cnt].push_back(val);
    };


    int t; cin >> t;
    while (t--) solve();
}
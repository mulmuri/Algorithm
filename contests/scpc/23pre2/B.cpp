#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
const int SIZE = 200001;


int n;



/*
+- 1
+-+- 3
+-+-+- 6
+-+-+-+- 10

이미 한 번 닫힌 상태에서 한 번 더 닫힐 때가 경계 상황
++--


*/

void solve(int tc) {
    ll ans = 0;
    string s; cin >> n >> s;
    vector<int> cnt(n+1, 0);

    int sz = 0;

    for (auto c: s) {
        if (c == '(') {
            sz++;
        } else if (c == ')') {
            if (sz == 0) {
                continue;
            }
            ll v = cnt[sz];
            ans +=  v * (v+1) / 2;
            cnt[sz] = 0;
            cnt[--sz]++;
        }
    }

    ll v = cnt[0];
    ans += v * (v+1) / 2;
    v = cnt[sz];
    ans += v * (v+1) / 2;

    cout << "Case #" << tc << endl;
    cout << ans << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
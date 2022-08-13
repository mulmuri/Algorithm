#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998244353;
const int INF = 1e18;
const int SIZE = 300001;


string s = "atcoder";
string t;

int32_t main() {
    fastio;
    
    cin >> t;

    for (int i=0; i<7; i++) {
        int idx = find(t.begin(), t.end(), s[i]) - t.begin();
        t[idx] = '0'+i;
        s[i] = '0'+i;
    }

    int cnt = 0;
    for (int i=0; i<7; i++) {
        for (int j=1; j<7; j++) {
            if (t[j-1] > t[j]) {
                swap(t[j-1], t[j]);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}
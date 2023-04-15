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


int n;
string s;

int32_t main() {
    fastio;

    cin >> n >> s;

    bool flag = true;
    for (auto c: s) {
        if (c == 'x') {
            cout << "No" << endl;
            return 0;
        }
    }
    for (auto c: s) {
        if (c == 'o') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

}
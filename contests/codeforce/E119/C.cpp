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


const int MOD = 998232453;
const int INF = (int)1e18;
const int SIZE = 200001;



int n, k, x;
string s;

void solve() {
    cin >> n >> k >> x >> s;
    reverse(s.begin(), s.end());
    s = s[0] + s;

    vector<int> a,b;

    int cnt = 0;
    s = s + s[n-1];
    s += ((s[n] == 'a') ? '*' : 'a');

    for (int i=1; i<=n+1; i++) {
        if (s[i] == s[i-1]) cnt++;
        else {
            if (s[i-1] == 'a') a.push_back(cnt);
            else b.push_back(cnt);
            cnt = 1;
        }
    }

    vector<int> arg;

    int cur, cum = 1;
    for (int i=0; i<b.size(); i++) {
        cur = b[i] * k + 1;
        cum *= cur;
        if (cum < 0) {
            break;
        }
        arg.push_back(cum);
    }

    vector<int> coeff(arg.size() + 1);

    int ix = x;
    coeff[arg.size()] = ix / arg[arg.size() - 1];

    for (int i=coeff.size()-1; i; i--) {
        coeff[i] = ix % arg[i];
    }








}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
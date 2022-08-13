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


int l,r;

string s = "aatcoder";

int32_t main() {
    fastio;
    
    cin >> l >> r;
    for (int i=l; i<=r; i++) cout << s[i];
}
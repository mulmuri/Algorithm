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



int n,s;

void solve() {
    cin >> n >> s;
    cout << s / (n*n) << endl;
}


int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
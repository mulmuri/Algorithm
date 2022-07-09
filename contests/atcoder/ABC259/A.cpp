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

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 300001;


int n,m,x,t,d;

int32_t main() {
    fastio;
    
    cin >> n >> m >> x >> t >> d;
    if (x <= m && m <= n) cout << t << endl;
    else if (m > n) cout << t + d*(x-n) << endl;
    else if (m < x) cout << t - d*(x-m) << endl;
}
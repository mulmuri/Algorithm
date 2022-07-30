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


int n,a,b;

int32_t main() {
    fastio;
    
    cin >> n >> a >> b;
    if (a <= b) cout << max((int)0, n-a+1);
    else if (n >= a) cout << (n/a-1) * b + min(n%a+1, b);
    else cout << 0;
}
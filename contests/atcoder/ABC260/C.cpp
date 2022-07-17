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


int n,x,y;


int red(int n);
int blue(int n);

int32_t main() {
    fastio;
    
    cin >> n >> x >> y;
    cout << red(n);
}

int red(int n) {
    if (n == 1) return 0;
    return red(n-1) + x * blue(n);
}

int blue(int n) {
    if (n == 1) return 1;
    return red(n-1) + y * blue(n-1);
}

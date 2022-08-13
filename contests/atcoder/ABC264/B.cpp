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


int r,c;
int arr[SIZE];

int32_t main() {
    fastio;
    
    cin >> r >> c;

    int v = min(min(r, 16-r), min(c, 16-c));
    cout << ((v%2 == 0) ? "white" : "black");
}
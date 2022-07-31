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
const int SIZE = 1001;


int n,m;
int a[SIZE];
int b[SIZE];

int mp[SIZE][SIZE];

int32_t main() {
    fastio;
    
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u,v; cin >> u >> v;
        mp[u][v] = 1;
    }

    int ans = 0;

    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            for (int k=j+1; k<=n; k++) {
                ans += (mp[i][j] * mp[j][k] * mp[i][k]);
            }
        }
    }
    cout << ans;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998244353;
const int INF = 1e9;
const int SIZE = 2001;



int n, m, k;
int s, t, x;
vector<int> adj[SIZE];

int dps[SIZE][SIZE];
int dpt[SIZE][SIZE];
int dpx[SIZE][SIZE];

int stox[SIZE];
int ttox[SIZE];
int xtox[SIZE];

int32_t main() {
    
    cin >> n >> m >> k >> s >> t >> x;

    for (int i=0; i<m; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "stop here";



    dps[0][s] = 1;
    for (int i=1; i<=k; i++) {
        for (int j=1; j<=k; k++) {
            for (int r: adj[j]) {
                dps[i][j] += dps[i-1][r];
                dps[i][j] %= MOD;
            }
        }
        stox[i] = dps[i][x];
        dps[i][x] = 0;
    }


    dpt[0][t] = 1;
    for (int i=1; i<=k; i++) {
        for (int j=1; j<=n; j++) {
            for (int r: adj[j]) {
                dpt[i][j] += dpt[i-1][r];
                dpt[i][j] %= MOD;
            }
        }
        ttox[i] = dpt[i][x];
        dpt[i][x] = 0;
    }

    xtox[0] = 1;
    dpx[0][x] = 1;
    for (int i=1; i<=k; i++) {
        for (int j=1; j<=n; j++) {
            for (int r: adj[j]) {
                dpx[i][j] += dpx[i-1][r];
                dpx[i][j] %= MOD;
            }
        }
        xtox[i] = dpx[i][x];
        dpx[i][s] = dpx[i][t] = 0;
    }

    int ans = 0;
    for (int i=1; i<k; i++) {
        for (int j=1; j<k-i; j++) {
            if ((k-i-j)%2 != 0) continue;
            ans += (stox[i] % MOD * ttox[j] % MOD  * xtox[k-i-j] % MOD);
            ans %= MOD;
        }
    }

    for (int i=0; i<=k; i++) cout << stox[i] <<' ';
    cout << endl;
    for (int i=0; i<=k; i++) cout << ttox[i] <<' ';
    cout << endl;
    for (int i=0; i<=k; i++) cout << xtox[i] <<' ';
    cout << endl;

    cout << ans;
}

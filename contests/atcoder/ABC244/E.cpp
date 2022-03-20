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
const int SIZE = 1001;



int n, m, k, s, t, x;
vector<int> adj[SIZE];

int dps[SIZE][SIZE];
int dpt[SIZE][SIZE];
int dpx[SIZE][SIZE];

int stox[SIZE];
int ttox[SIZE];
int xtox[SIZE];

int32_t main() {
    //fastio;
    
    cin >> n >> m >> k >> s >> t >> x;


    for (int i=0; i<m; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);                
    }

    cout << "!@#";


    dps[0][s] = 1;
    for (int i=1; i<=k; i++) {
        for (int j=1; j<=k; k++) {
            for (int r: adj[j]) {
                dps[i][j] += dps[i-1][r];
            }
        }
        stox[i] = dps[i][s];
        dps[i][s] = 0;
    }


    dpt[0][t] = 1;
    for (int i=1; i<=k; i++) {
        for (int j=1; j<=k; k++) {
            for (int r: adj[j]) {
                dpt[i][j] += dpt[i-1][r];
            }
        }
        ttox[i] = dpt[i][t];
        dpt[i][t] = 0;
    }

    dpx[0][x] = 1;
    for (int i=1; i<=k; i++) {
        for (int j=1; j<=k; k++) {
            for (int r: adj[j]) {
                dpx[i][j] += dpx[i-1][r];
            }
        }
        xtox[i] = dpx[i][x];
    }

    int ans = 0;
    for (int i=1; i<=k; i++) {
        for (int j=1; j<k-i; j++) {
            ans *= stox[i] * ttox[j] * xtox[k-i-j];
            ans %= MOD;
        }
    }

    cout << ans;
}

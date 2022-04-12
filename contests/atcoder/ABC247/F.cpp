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
const int SIZE = 300001;



int n;
int a[SIZE], b[SIZE];
int adj[SIZE];
int vst[SIZE];

int fibo[SIZE];

int32_t main() {
    fastio;
    
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];

    for (int i=1; i<=n; i++) adj[a[i]] = b[i];

    fibo[1] = 1;
    for (int i=2; i<=n; i++) fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;

    int ans = 1;

    for (int i=1; i<=n; i++) {
        if (vst[i]) continue;

        vector<int> cycle;
        for (int j=i; vst[j]==0; j=adj[j]) {
            vst[j] = 1;
            cycle.push_back(j);
        }
        int s = cycle.size();

        if (s != 1)
            ans = ans * (fibo[s] + fibo[s-1]*2) % MOD;
    }

    cout << ans;
}
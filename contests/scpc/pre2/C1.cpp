#include <bits/stdc++.h>
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


int n,m,k;
int sz;

vector<pair<int,int>> adj[SIZE];
vector<pair<int,int>> iadj[SIZE];
int vst[SIZE];
int loop[SIZE];
int dp[SIZE][3];
int cnt[SIZE][3];

vector<int> stk;



bool hasCycle0(int t) {
    vst[t] = 1;
    loop[t] = 1;

    for (auto[n, c]: adj[t]) {
        if (vst[n] && loop[n]) {
            return 1;
        }

        if (!vst[n] && hasCycle0(n)) {
            loop[t] = 0;
            return 1;
        }
    }

    loop[t] = 0;
    return 0;
}


bool hasCycle3(int t) {
    vst[t] = 1;
    loop[t] = 1;

    for (auto[n, c]: adj[t]) {
        if (vst[n] && loop[n]) {
            cnt[t][c]++;
            if (cnt[t][0] > cnt[n][0] && cnt[t][1] > cnt[n][1] && cnt[t][2] > cnt[n][2]) {
                loop[t] = 0;
                return 1;
            }
            cnt[t][c]--;
        }

        if (vst[n]) continue;

        cnt[n][0] = cnt[t][0];
        cnt[n][1] = cnt[t][1];
        cnt[n][2] = cnt[t][2];
        cnt[n][c]++;

        if (hasCycle3(n)) {
            loop[t] = 0;
            return 1;
        }
    }

    loop[t] = 0;
    return 0;
}



void dfs(int t) {
    vst[t] = 1;
    for (auto[n, c]: adj[t]) {
        if (vst[n]) continue;
        dfs(n);
    }
    stk.push_back(t);
}



int solve0() {
    for (int i=0; i<m; i++) {
        int u,v; char c;
        cin >> u >> v >> c;

        c = c - 'A';
        u = (u-1)*3+c;
        v = (v-1)*3+(c+1)%3;

        adj[u].push_back({v, c});
        iadj[v].push_back({u, c});
    }

    for (int i=0; i<sz; i++) if (hasCycle0(i)) return -1;

    fill(vst, vst+sz, 0);
    for (int i=0; i<sz; i++) if (vst[i] == 0) dfs(i);
    reverse(stk.begin(), stk.end());

    int ans = 0;
    for (int t: stk) {
        for (auto[e, c]: iadj[t]) dp[t][0] = max(dp[t][0], dp[e][0]+1);
        ans = max(ans, dp[t][0]);
    }

    return ans;
}



int solve3() {
    for (int i=0; i<m; i++) {
        int u,v; char c;
        cin >> u >> v >> c;

        c = c - 'A';

        adj[u].push_back({v, c});
        iadj[v].push_back({u, c});
    }

    for (int i=0; i<sz; i++) if (hasCycle0(i)) return -1;

    fill(vst, vst+sz, 0);
    for (int i=0; i<sz; i++) if (vst[i] == 0) dfs(i);
    reverse(stk.begin(), stk.end());

    int ans = 0;
    for (int t: stk) {
        for (auto[p, c]: iadj[t]) {
            dp[t][c] = max(dp[t][c], dp[p][(c+2)%3]+1);
        }

        for (auto[n, c]: adj[t]) {
            for (int u=0; u<3; u++) dp[n][u] = max(dp[n][u], dp[t][u]);
        }

        ans = max(ans, dp[t][0]);
        ans = max(ans, dp[t][1]);
        ans = max(ans, dp[t][2]);

        //cout << dp[t][0] <<' '<< dp[t][1] <<' '<< dp[t][2] << endl;
    }

    return ans;
}



int solve1() {
    for (int i=0; i<m; i++) {
        int u,v; char c;
        cin >> u >> v >> c;
        c = c - 'A';
        u = (u-1)*3+c;
        v = (v-1)*3+(c+1)%3;

        adj[u].push_back({v, c});
        iadj[v].push_back({u, c});
    }

    for (int i=0; i<sz; i++) if (hasCycle0(i)) return -1;

    fill(vst, vst+sz, 0);
    for (int i=0; i<sz; i++) if (vst[i] == 0) dfs(i);
    reverse(stk.begin(), stk.end());

    int ans = 0;

    for (int t: stk) {
        for (auto[e, c]: iadj[t]) dp[t][0] = max(dp[t][0], dp[e][0]+1);
        ans = max(ans, dp[t][0]);
    }

    for (int u=1; u<=k; u++) {
        for (int i=0; i<sz; i++) {
            for (auto[j, c]: iadj[i]) dp[i][u] = max(dp[i][u], dp[j/3*3 + (j+1)%3][u-1]);
        }
        for (int t: stk) {
            for (auto[e, c]: iadj[t]) dp[t][u] = max(dp[t][u], dp[e][u]+1);
            ans = max(ans, dp[t][u]);
        }
    }

    return ans;
}



void solve(int tc) {
    cin >> n >> m >> k;

    if (k == -1) sz = n+1;
    else sz = n*3;

    fill(vst, vst+sz, 0);
    fill(loop, loop+sz, 0);
    for (int i=0; i<sz; i++) dp[i][0] = dp[i][1] = dp[i][2] = 0;
    for (int i=0; i<sz; i++) cnt[i][0] = cnt[i][1] = cnt[i][2] = 0;

    for (int i=0; i<sz; i++) {
        adj[i].clear();
        iadj[i].clear();
    }
    stk.clear();

    int ans;
    if (k == 0) ans = solve0();
    if (k == -1) ans = solve3();
    if (k > 0) ans = solve1();

    cout << "Case #" << tc << endl;
    cout << ans << endl;
}



int32_t main() {
    fastio;

    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

const int MAX = 1000005;
int n, m;
int adj[MAX];
int dist[MAX];
set<int> curr_vis;
bool vis[MAX];
int k = 0;

void dfs(int now){
    int nxt = adj[now];
    vis[now] = true;
    curr_vis.insert(now);

    if (nxt == 0){
        dist[now] = 1;
        return;
    }

    if (vis[nxt] == false){
        dfs(nxt);
        dist[now] = dist[nxt] + 1;
        return;
    }
    else{
        if (curr_vis.find(nxt) == curr_vis.end()){
            dist[now] = dist[nxt] + 1;
            return;
        }
        else{
            k = nxt;
            dist[now] = 1;
            return;
        }
    }
}

void dfs2(int now, int init){
    dist[now] = dist[init];
    int nxt = adj[now];
    if (nxt == init) return;
    else {dfs2(nxt, init); return;}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;

    F0R(i, m)
    {
        int a, b;
        cin >> a >> b;
        adj[a + 1] = b + 1;
    }

    FOR(i, 1, n + 1)
    {
        if (vis[i] == false)
        {
            k = 0; curr_vis.clear();
            dfs(i);

            if (k != 0){
                dfs2(k,k);
            }
        }
    }
    int ans = 0;
    F0R(i,n+1) ans = max(ans, dist[i]);

    cout << ans;
}

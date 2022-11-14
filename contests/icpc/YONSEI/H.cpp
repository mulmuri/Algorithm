#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAX_D = 17;
const int MAXN = 200001;

int N, p[MAXN][MAX_D], depth[MAXN];
vector<int> adj[MAXN];
bool vst[MAXN];
int cnt[MAXN];

void dfs(int u, int d)
{
    cnt[u] = 1;

    vst[u] = true;
    depth[u] = d;
    for (int v : adj[u])
    {
        if (!vst[v])
        {
            p[v][0] = u;
            dfs(v, d + 1);
            cnt[u] += cnt[v];
        }
    }
}

void constructLca()
{
    dfs(0, 0);
    for (int j = 1; j < MAX_D; j++)
    {
        for (int i = 1; i < N; i++)
        {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }
}

int findLca(int u, int v)
{
    // Make u have u higher depth
    if (depth[u] < depth[v])
        swap(u, v);

    // Elevate u to the depth of v
    int depth_diff = depth[u] - depth[v];
    for (int j = MAX_D - 1; j >= 0; j--)
    {
        if (depth_diff & (1 << j))
        {
            u = p[u][j];
        }
    }

    if (u == v)
        return u;

    for (int j = MAX_D - 1; j >= 0; j--)
    {
        if (p[u][j] != p[v][j])
        {
            u = p[u][j];
            v = p[v][j];
        }
    }

    return p[u][0];
}

int q;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> q;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    constructLca();

    int r = 0;

    while (q--)
    {
        int t, x;
        cin >> t >> x;
        x--;

        if (t == 1)
        {
            r = x;
        }
        else if (t == 2)
        {
            int p = findLca(x, r);

            vector<int> item;

            if (p != x)
            {
                for (int nxt : adj[x])
                {
                    if (depth[nxt] > depth[x])
                        item.push_back(cnt[nxt]);
                }
            }
            else
            {
                for (int nxt : adj[x])
                {
                    if (depth[nxt] > depth[x]) {
                        if (findLca(nxt, r) == x) item.push_back(cnt[nxt]);
                    }
                    else item.push_back(N - cnt[x]);
                }
            }

            //for (auto e: item) cout << e << ' '<< endl;

            int x2sum = 0, xsum = 0;
            for (int e : item)
                x2sum += e * e;
            for (int e : item)
                xsum += e;
            
            cout << (xsum * xsum - x2sum) / 2 + xsum << endl;
        }
    }
}
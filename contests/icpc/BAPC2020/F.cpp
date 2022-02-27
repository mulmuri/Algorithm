#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int SIZE = 1000;
const int INF = 1e5;

int n,m,p,g;

int dist[SIZE];
vector<pair<int,int>> adj[SIZE];

int parent[SIZE];
vector<int> tree[SIZE];

int person[SIZE];
bool found[SIZE];

int dp[SIZE];

int dfs(int t, int p) {
    int pr = person[t];
    for (auto n: tree[t]) {
        if (n == pr) continue;

        pr += dfs(n, t);
    }
    dp[t] = (pr - 1) * dist[t];
    if (t == 3) cout << pr <<' '<< dist[t] << endl;
    return pr;
}

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main() {
    cin >> n >> m >> p >> g;

    for (int i=0; i<p; i++) {
        int c;
        cin >> c;
        person[c]++;
    }

    for (int i=0; i<m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    fill(dist, dist+n+1, INF);
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int t = pq.top().second;
        pq.pop();

        if (found[t]) continue;
        found[t] = true;

        for (auto e: adj[t]) {
            int n = e.second, d = e.first;
            if (dist[n] > dist[t] + d) {
                dist[n] = dist[t] + d;
                parent[n] = t;
                pq.push({dist[n], n});
            }
        }1
    }


    for (int i=2; i<=n; i++) tree[parent[i]].push_back(i);

    dfs(1, 0);

    int ticket = 0;
    for (int i=1; i<=n; i++) ticket = max(ticket, dp[i]);

    int sum = 0;
    for (int i=1; i<=n; i++) sum += person[i] * dist[i];

    cout << sum <<' '<< ticket;
}

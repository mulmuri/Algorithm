#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 3000;
const int MAX_V = MAX_N+2;
const int INF = 1e9;

int c[MAX_V][MAX_V], f[MAX_V][MAX_V];
int level[MAX_V];
int work[MAX_V];
vector<int> adj[MAX_V];
 

void init(int sz) {
    fill(c[0], c[MAX_V], 0);
    fill(f[0], f[MAX_V], 0);
    for (int i=0; i<MAX_V; i++) adj[i].clear();
}

bool bfs(int S, int E) {
    fill(level, level+MAX_V, -1);
    level[S] = 0;
    queue<int> Q;
    Q.push(S);

    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        for(int next: adj[curr]){
            if(level[next] == -1 && c[curr][next]-f[curr][next] > 0){
                level[next] = level[curr] + 1;
                Q.push(next);
            }
        }
    }
    return level[E] != -1;
}
 

int dfs(int curr, int dest, int flow) {
    if (curr == dest) return flow;
 
    for (int &i=work[curr]; i<adj[curr].size(); i++){
        int next = adj[curr][i];
        if (level[next] == level[curr]+1 && c[curr][next]-f[curr][next] > 0){
            int df = dfs(next, dest, min(c[curr][next]-f[curr][next], flow));
            if (df > 0){
                f[curr][next] += df;
                f[next][curr] -= df;
                return df;
            }
        }
    }
    return 0;
}

int dinic(int S, int E) {
    int total = 0;

    while (bfs(S,E)) {
        fill(work, work+MAX_V, 0);
        while (1) {
            int flow = dfs(S, E, INF);
            if (flow == 0) break;
            total += flow;
        }
    }

    return total;
}


int n,m;
int arr[MAX_N][MAX_N];

void solve() {
    cin >> n >> m;

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin >> arr[i][j];

    int S = MAX_V-2;
    int E = MAX_V-1;
    init(E+2);

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        int u = i*m + j;

        if ((i+j)%2 == 0) {
            c[S][u] = arr[i][j];
            adj[S].push_back(u);
            adj[u].push_back(S);
        } else {
            c[u][E] = arr[i][j];
            adj[u].push_back(E);
            adj[E].push_back(u);
        }

        int ni = i+1;
        if (ni != n) {
            int v = ni*m + j;
            c[u][v] = INF;
            c[v][u] = INF;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int nj = j+1;
        if (nj != m) {
            int v = i*m + nj;
            c[u][v] = INF;
            c[v][u] = INF;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int sum = 0;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) sum += arr[i][j];

    int pair = dinic(S,E);
    int ans = pair + (sum - pair*2);

    cout << ans << endl;
}



int main() {
    int t; cin >> t;
    while (t--) solve();
}




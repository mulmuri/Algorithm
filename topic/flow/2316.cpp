// 도시 왕복하기

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 1000;
const int MAX_V = MAX_N+2;
const int INF = 1000000000;
 
int N, c[MAX_V][MAX_V], f[MAX_V][MAX_V];
int level[MAX_V];
int work[MAX_V];
vector<int> adj[MAX_V];
 

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


int n, p;

int main() {
    cin >> n >> p;

    for (int i=0; i<p; i++) {
        int u, v;
        cin >> u >> v;
        int iu = u*2-1, ou = u*2;
        int iv = v*2-1, ov = v*2;

        c[ou][iv] = INF;
        c[ov][iu] = INF;
        adj[ou].push_back(iv);
        adj[iv].push_back(ou);
        adj[ov].push_back(iu);
        adj[iu].push_back(ov);
    }

    for (int i=1; i<=n; i++) {
        int u = i*2-1;
        int v = i*2;

        c[u][v] = 1;
        c[v][u] = 1;
        adj[u].push_back(v)
        adj[v].push_back(u);
    }

    cout << dinic(2, 3);
}


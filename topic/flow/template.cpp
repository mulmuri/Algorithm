#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 500;
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


int n;

int main() {
    cin >> n;

    for (int i=0; i<n; i++) {
        char pu,pv; int w;
        cin >> pu >> pv >> w;

        int u = pu % 32 + 32*(pu/96);
        int v = pv % 32 + 32*(pv/96);
        c[u][v] += w;
        c[v][u] += w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << dinic(1, 26);
}




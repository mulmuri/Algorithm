#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int SIZE = 1000;
const int INF = 1000000000;

int n,m;
int A[SIZE], B[SIZE], dist[SIZE];
bool used[SIZE];
vector<int> adj[SIZE];

void bfs(int sz) {
    queue<int> Q;
    for (int i = 0; i < sz; i++) {
        if (!used[i]) {
            dist[i] = 0;
            Q.push(i);
        } else dist[i] = INF;
    }

    while (!Q.empty()) {
        int a = Q.front();
        Q.pop();
        for (int b: adj[a]) {
            if (B[b] != -1 && dist[B[b]] == INF) {
                dist[B[b]] = dist[a] + 1;
                Q.push(B[b]);
            }
        }
    }
}

bool dfs(int a) {
    for (int b: adj[a]) {
        if (B[b] == -1 || (dist[B[b]] == dist[a] + 1 && dfs(B[b]))) {
            used[a] = true;
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

int hopcroft_karp(int sz) {
    int match = 0;
    fill(A, A + SIZE, -1);
    fill(B, B + SIZE, -1);
    while (1) {
        bfs(sz);

        int flow = 0;
        for (int i = 0; i < sz; i++)
            if (!used[i] && dfs(i)) flow++;

        if (flow == 0) break;
        match += flow;
    }
    return match;
}

int main() {
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        int t; cin >> t;
        while (t--) {
            int j; cin >> j;
            adj[i].push_back(j);
        }
    }

    cout << hopcroft_karp(n+1) << endl;

    for (int i=1; i<=m; i++) if (B[i] != -1) cout << B[i] <<' ';
    cout << endl;
    for (int i=1; i<=n; i++) if (A[i] != -1) cout << A[i] <<' ';
}

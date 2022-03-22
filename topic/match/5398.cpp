#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int SIZE = 2002;
const int INF = 1000000000;

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
    fill(dist, dist+SIZE, 0);
    fill(used, used+SIZE, 0);

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



int r,c;
int arr[SIZE][SIZE];


void solve() {
    cin >> r >> c;

    fill(arr[0], arr[SIZE], 0);
    for (int i=0; i<SIZE; i++) adj[i].clear();

    while (r--) {
        int x,y;
        string s;
        cin >> x >> y >> s;
        for (int j=0; j<s.size(); j++) {
            arr[x+j][y] = s[j];
        }
    }

    while (c--) {
        int x,y;
        string s;
        cin >> x >> y >> s;
        for (int j=0; j<s.size(); j++) {
            if ((arr[x][y+j] != 0) && (arr[x][y+j] != s[j])) {
                adj[x].push_back(y+j);
            }
        }
    }

    int flow = hopcroft_karp(SIZE);
    cout << r + c - flow << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}
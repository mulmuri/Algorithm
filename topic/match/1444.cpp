#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
const int SIZE = 53*53;
const int INF = 1000000000;

int N,M;
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


set<pair<int,int>> node;

set<int> st;

int main() {
    string s; cin >> s;
    int n = s.size();

    //st.insert( (s[0]%32 + s[0]/96*26)*26 + (s[1]%32 + s[1]/96*26));
    //st.insert( (s[n-2]%32 + s[n-2]/96*26)*26 + (s[n-1]%32 + s[n-1]/96*26));

    for (int i=1; i<n-1; i++) {
        int a = s[i-1]%32 + s[i-1]/96*26;
        int b = s[i]%32 + s[i]/96*26;
        int c = s[i+1]%32 + s[i+1]/96*26;

        //if (st.count(a*26+b) || st.count(b*26+c)) continue;

        adj[a*27+b].push_back(b*27+c);
        adj[b*27+c].push_back(a*27+b);
    }

    int match = hopcroft_karp(SIZE);
    cout << match;
}


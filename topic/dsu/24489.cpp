#include <bits/stdc++.h>
using namespace std;


const int SIZE = 200001;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'


struct info {
    char type;
    int x,y;
};



int n,q;

info query[SIZE];
set<int> adj[SIZE];
int activated[SIZE];
int ans[SIZE];

int idx = 1;
int trans[SIZE];



void dfs(int t, int time) {
    activated[t] = 1;
    ans[t] = time;
    for (int n: adj[t]) {
        if (!activated[n]) {
            dfs(n, time);
        }
    }
}


/*
void dfs(int st, int time) {
    queue<int> q;
    activated[st] = 1;
    q.push(st);

    while (!q.empty()) {
        int t = q.front();
        q.pop();
        ans[t] = time;

        for (int n: adj[t]) {
            if (!activated[n]) {
                activated[n] = 1;
                q.push(n);
            }
        }
    }
}
*/


int main() {
    cin >> n >> q;
    fill(activated+1, activated+n+1, 1);

    for (int i=0; i<q; i++) {
        int x,y,e;
        cin >> query[i].type;
        switch (query[i].type) {
            case 'A':
                cin >> x >> y;
                adj[x].insert(y);
                adj[y].insert(x);
                query[i].x = x;
                query[i].y = y;
                trans[idx++] = i;
                break;
            case 'D':
                cin >> x;
                activated[x] = 0;
                query[i].x = x;
                break;
            case 'R':
                cin >> e;
                e = trans[e];
                x = query[e].x;
                y = query[e].y;
                adj[x].erase(y);
                adj[y].erase(x);
                query[i].x = x;
                query[i].y = y;
                break;
        }
    }

    for (int i=1; i<=n; i++) {
        if (activated[i]) {
            dfs(i, q);
        }
    }
   

    for (int i=q-1; i>=0; i--) {
        int x,y;
        switch (query[i].type) {
            case 'A':
                break;
            case 'D':
                x = query[i].x;
                if (!activated[x]) dfs(x, i);
                break;
            case 'R':
                x = query[i].x;
                y = query[i].y;
                if (activated[x] && !activated[y]) dfs(y, i);
                if (activated[y] && !activated[x]) dfs(x, i);
                adj[x].insert(y);
                adj[y].insert(x);
                break;
        }
    }

    for (int i=1; i<=n; i++) cout << ans[i] << endl;
}
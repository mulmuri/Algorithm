#include<bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

typedef long long ll;

const int SIZE = 100001;


int n;
string s;
vector<int> adj[SIZE];
map<pair<int,int>, ll> merged[SIZE];
char type[SIZE];

ll ans = 0;


void add(pair<int,int> &p, char chr) {
    switch (chr) {
        case 'U':
            p.first++;
            p.second++;
            break;
        case 'P':
            p.first--;
            p.second++;
            break;
        case 'C':
            p.second--;
            break;
    }
}



int dfs(int t, int p) {
    int chr = s[t-1];

    int to = 0;
    merged[to].clear();

    for (int n: adj[t]) {
        if (n == p) continue;
        int from = dfs(n, t);

        if (merged[to].size() < merged[from].size()) swap(from, to);
        for (auto it=merged[from].begin(); it!=merged[from].end(); it++) {
            pair<int,int> target(it->first);
            
        }

    }

    cout << t <<' '<< merged[t].size() << endl;

    return t;
}


int main() {
    cin >> n >> s;
    for (int i=1; i<n; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << ans;
}
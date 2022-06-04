#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 300001;


int n,m;
vector<int> adj[SIZE];
int val[SIZE][4];

int q;

int tmp;


void bfs(int s) {
    queue<pair<int,int>> q;
    q.push({s, 0});
    vector<int> found = {s};
    int sum = 0;
    val[s][0] = s;

    int newlv = 1;

    while (!q.empty()) {
        auto[t, lv] = q.front();
        //cout << t <<' '<< lv << endl;
        q.pop();

        if (lv > newlv) {
            val[s][newlv] = sum;
            newlv++;            
        }

        if (lv > 3) break;
        sum += t;

        for (int n: adj[t]) {
            if (find(found.begin(), found.end(), n) == found.end()) {
                q.push({n, lv+1});
                found.push_back(n);
            }
        }
    }
    for (int i=newlv; i<=3; i++) {
        val[s][i] = max(sum, val[s][i-1]);
    }

}



int32_t main() {
    fastio;
    
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=1; i<=n; i++) bfs(i);

    //for (int i=0; i<=3; i++) {
    //    for (int j=1; j<=n; j++) {
    //        cout << val[j][i] <<' ';
    //    }
    //    cout << endl;
    //}

    cin >> q;
    while (q--) {
        int x,k;
        cin >> x >> k;
        cout << val[x][k] << endl;
    }
}
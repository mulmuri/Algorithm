#include <bits/stdc++.h>
using namespace std;

#define int long long

const int SIZE = 1001;
const int INF = (int)1e18;

pair<int,int> edge[SIZE][SIZE];
int w[SIZE][SIZE];
int n,t,m;
int s,e;

int dp[2][SIZE*10];



int32_t main() {
    cin >> n >> t >> m;
    cin >> s >> e;

    for (int i=1; i<=t; i++) {
        for (int j=0; j<m; j++) {
            int a,b,c;
            cin >> a >> b >> c;

            edge[i][j] = {a,b};
            w[i][j] = c;
        }
    }

    for (int j=0; j<n; j++) dp[0][j] = dp[1][j] = INF;
    dp[0][s] = 0;

    for (int i=1; i<=t; i++) {
        for (int j=0; j<n; j++) dp[i%2][j] = min(dp[i%2][j], dp[(i+1)%2][j]);

        for (int j=0; j<m; j++) {
            auto[a, b] = edge[i][j];
            int c = w[i][j];

            dp[i%2][b] = min(dp[i%2][b], dp[(i+1)%2][a] + c);
            dp[i%2][a] = min(dp[i%2][a], dp[(i+1)%2][b] + c);
        }
    }

    if (dp[t%2][e] == INF) cout << -1;
    else cout << dp[t%2][e];
}
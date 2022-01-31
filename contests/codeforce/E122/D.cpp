#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 1001


int n,k;

int table[SIZE];
int value[SIZE];
int cost[SIZE];
int dp[SIZE*13][2];

void solve() {
    cin >> n >> k;
    k = min(k, SIZE*13);
    for (int i=0; i<n; i++) {
        int b;
        cin >> b;
        cost[i] = table[b];
    }
    for (int i=0; i<n; i++) cin >> value[i];

    for (int i=0; i<n; i++) {
        for (int j=0; j<=k; j++) dp[j][i%2] = dp[j][(i+1)%2];
        for (int j=0; j<=k-cost[i]; j++)
            dp[j+cost[i]][i%2] = max(dp[j+cost[i]][(i+1)%2],dp[j][(i+1)%2]+value[i]);
    }

    cout << dp[k][(n-1)%2] << endl;
    for (int i=0; i<=k; i++) dp[i][0] = dp[i][1] = 0;
}


int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    fill(table, table+SIZE, 13);
    table[1] = 0;

    for (int i=1; i<=SIZE; i++) {
        for (int j=1; j<=i; j++) {
            int k = i + i/j;
            if (k >= SIZE) continue;
            table[k] = min(table[k], table[i]+1);
        }
    }

    int t; cin >> t;
    while (t--) solve();
}
#include <iostream>
using namespace std;



int arr[302][302], dp[302][302];
int n,m, ans;

bool isOk(int y, int x) {
    return 1 <= y && y <= n && 1 <= x && x <= m;
}


int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin >> arr[i][j];

    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
    }

    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        for (int k=i; k<i+10; k++) for (int l=j; l<j+10; l++) {
            if (!isOk(k, l)) continue;
            if ((k-i+1)*(l-j+1) > 10) continue;

            int sum = dp[k][l] + dp[i-1][j-1] - dp[k][j-1] - dp[i-1][l];
            if (sum == 10) ans++;
        }
    }

    cout << ans;
}
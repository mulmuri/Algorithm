#include <iostream>
#include <algorithm>
using namespace std;




int n, d;
long long Ci[8001];
long long sum[8001];

long long dp[801][8001], properK[801][8001];

// 문제에 맞게 Cost 정의
long long Cost(long long a, long long b) {
    return (sum[b] - sum[a - 1]) * (b - a + 1);
}

// dp[t][i] = min_{k<i} (dp[t-1][k] + C[k][i]) 꼴의 문제를 풀고자 할 때,
// 아래 함수는 dp[t][l~r]을 채운다.

void Dnc(int t, int l, int r, int p, int q) {
    if (l > r) return;

    int mid = (l + r) >> 1;
    dp[t][mid] = -1;
    properK[t][mid] = -1;

    for (int k = p; k <= q; ++k) {
        long long current = dp[t - 1][k] + Cost(k+1, mid);
        if (dp[t][mid] == -1 || dp[t][mid] > current) {
            dp[t][mid] = current;
            properK[t][mid] = k;
        }
    }

    Dnc(t, l, mid - 1, p, properK[t][mid]);
    Dnc(t, mid + 1, r, properK[t][mid], q);
}

int main() {
    cin >> n >> d;

    for (int i=1; i<=n; i++) cin >> t[i];
    for (int i=1; i<=n; i++) cin >> v[i];
}
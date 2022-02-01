#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
#define MOD 998244353
#define INF 1e9
#define SIZE 2000001


int n,d;

long long power[SIZE];

int main() {
    fastio;

    cin >> n >> d;
    power[0] = 1;
    for (int i=1; i<n*2; i++) power[i] = 2*power[i-1]%MOD;

    if (d == 1) {
        cout << power[n+1] - 4;
        return 0;
    }

    long long ans = 0;

    for (int i=1; i<n; i++) {
        if (i*2 < d) continue;

        long long tmp = power[d-2] * power[n-1-i] % MOD;

        if (i >= d) tmp *= (d+3);
        else tmp *= (i*2 - d + 1);

        ans += tmp;
        ans %= MOD;
    }

    cout << ans*2%MOD;
}
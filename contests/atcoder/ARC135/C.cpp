#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998244353;
const int INF = 1e18;
const int SIZE = 300001;


int n;
int arr[SIZE];

int bit[32];

int32_t main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];

    for (int i=1; i<=n; i++) for (int j=0; j<30; j++) {
        bit[j] += (bool)(arr[i] & (1 << j));
    }

    int sum = accumulate(arr+1, arr+1+n, (int)0);

    int dif = 0;
    for (int i=1; i<=n; i++) {
        int v = 0;
        for (int j=0; j<30; j++) {
            if (arr[i] & (1 << j)) {
                v += (n - bit[j]*2) * (1 << j);
            }
        }
        dif = max(dif, v);
    }

    cout << sum + dif;
}
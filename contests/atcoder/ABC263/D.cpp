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


int n,l,r;
int arr[SIZE];
int pfsum[SIZE];
int pfmin[SIZE];



int32_t main() {
    fastio;
    
    cin >> n >> l >> r;
    for (int i=1; i<=n; i++) cin >> arr[i];

    for (int i=1; i<=n; i++) pfsum[i] = pfsum[i-1] + arr[i];

    for (int i=1; i<=n; i++) pfmin[i] = min(pfmin[i-1] + arr[i], l*i);

    int ans = INF;
    for (int i=0; i<=n; i++) ans = min(ans, pfmin[i] + (n-i)*r);
    cout << ans;
}
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

int32_t main() {
    fastio;
    
    cin >> n;
    for (int i=2; i<=n; i++) cin >> arr[i];
    int cnt = 0;
    for (int i=n; i != 1; i = arr[i]) cnt++;
    cout << cnt;
}
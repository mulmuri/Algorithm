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
const int SIZE = 300005;


int n;
int s[SIZE];
int ds[SIZE];

int t[5];
int ans[SIZE];

int32_t main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> s[i];
    for (int i=1; i<n; i++) ds[i] = s[i+1] - s[i];

    for (int tmp = 0, i=1; i<n; i+=3) {tmp -= ds[i]; t[1] = max(t[1], tmp);}
    for (int tmp = 0, i=2; i<n; i+=3) {tmp -= ds[i]; t[2] = max(t[2], tmp);}
    for (int tmp = 0, i=3; i<n; i+=3) {tmp -= ds[i]; t[3] = max(t[3], tmp);}
    
    int _sum = t[1] + t[2] +t[3];
    if (_sum > s[1]) {
        cout << "No";
        return 0;
    }

    ans[1] = t[1];
    ans[2] = t[2];
    ans[3] = s[1] - t[1] - t[2];
    for (int i=1; i<n; i++) ans[i+3] = ans[i] + ds[i];

    cout << "Yes" << endl;
    for (int i=1; i<=n+2; i++) cout << ans[i] <<' ';
}
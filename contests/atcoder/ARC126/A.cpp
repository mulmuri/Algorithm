#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
#define MOD 998232453
#define INF 1e9
#define SIZE 200001
#define int long long

int n;
int arr[SIZE];

void solve() {
    int n2,n3,n4;
    cin >> n2 >> n3 >> n4;

    int ans = 0;

    int a = min(n3/2, n4);
    n3 -= a*2; n4 -= a;
    ans += a;

    int b = min(n3/2, n2/2);
    n3 -= b*2; n2 -= b*2;
    ans += b;

    int c = min(n2, n4/2);
    n2 -= c; n4 -= c*2;
    ans += c;

    int d = min(n2/3, n4);
    n2 -= d*3; n4 -= d;
    ans += d;

    int e = n2/5;
    n2 -= e*5;
    ans += e;

    cout << ans << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl "\n"
#define MOD 998232453
#define INF 1e9
#define SIZE 200001
#define int long long

int n, b, x, y;
int arr[SIZE];



void solve() {
    cin >> n >> b >> x >> y;

    for (int i=1; i<=n; i++) {
        if (arr[i-1] + x > b) {
            arr[i] = arr[i-1] - y;
        } else {
            arr[i] = arr[i-1] + x;
        }
    }
    int sum = 0;
    for (int i=1; i<=n; i++) sum += arr[i];
    cout << sum << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();    
}
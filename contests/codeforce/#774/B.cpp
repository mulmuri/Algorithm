#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define MOD 998244353
#define INF 2e9
#define SIZE 200001



int n;
int arr[SIZE];

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int val = arr[0];
    int i = 1, j = n-1;
    while (i <= j) {
        val -= arr[j--];
        val += arr[i++];

        if (val < 0 ){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}


int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
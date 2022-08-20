#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200001;


int n,k,b,s;
int arr[SIZE];


void solve() {
    cin >> n >> k >> b >> s;
    //cout << "output ";
    //for (int i=1; i<=n; i++) cin >> arr[i];
    //int sum = accumulate(arr+1, arr+1+n, (int)0);

    if (s/k == b) {
        for (int i=1; i<n; i++) cout << 0 <<' ';
        cout << s << endl;
        return;
    }

    arr[n] = k * (b+1) - 1;
    int left = s - arr[n];
    if (left > (n-1) * (k-1) || left < 0) {
        cout << -1 << endl;
        return;
    }

    if (left == (n-1)*(k-1)) {
        for (int i=1; i<n; i++) cout << k-1 <<' ';
        cout << arr[n] << endl;
        return;
    }

    for (int i=0; i<left/(k-1); i++) cout << k-1 <<' ';
    for (int i=left/(k-1); i<n-2; i++) cout << 0 <<' ';
    cout << left%(k-1) <<' '<< arr[n] << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
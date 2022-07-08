#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;
typedef pair<int,int> pii;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200001;


int n;
int arr[SIZE];


void solve() {
    for (int i=0; i<4; i++) cin >> arr[i];
    int sum = 0;
    for (int i=0; i<4; i++) sum += arr[i];
    if (sum == 0) cout << 0 << endl;
    else if (sum == 4) cout << 2 << endl;
    else cout << 1 << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
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


void solve() {
    cin >> n;
    string arr; cin >> arr;
    arr = 'x' + arr + 'x';

    int cnt = 0;
    for (int i=2; i<=n; i+=2) {
        if (arr[i] != arr[i-1]) cnt++;
    }
    cout << cnt << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
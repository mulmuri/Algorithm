#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200001;


int n, a, b;


void solve(int tc) {
    cin >> n >> a >> b;
    if (a < b) swap(a, b);

    for (int i=0; i<=n/a; i++) {
      if ((n - a*i) % b == 0) {
        cout << "Case #" << tc << endl << i + (n - a*i)/b << endl;
        return;
      }
    }
}

int32_t main() {
    fastio;

    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
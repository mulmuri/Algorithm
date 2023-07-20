#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 300001;


int n;
int arr[SIZE];




void solve() {
  cin >> n;

  if (n == 1) {
    cout << 1 << endl;
    return;
  }

  if (n == 2) {
    cout << "1 2" << endl;
    return;
  }

  cout << 2 << ' ';
  for (int i=2; i<=n/2; i++) cout << i+2 <<' ';
  cout << 1 << ' ';
  for (int i=n/2+2; i<n; i++) cout << i+1 <<' ';
  cout << 3 << endl; 

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
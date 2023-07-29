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
const int SIZE = 500001;


int n, a, b;
int arr[SIZE];

int getRoot(int n) {
  int x = 1;
  while (x*x <= n) x++;
  return x-1;
}




void solve(int tc) {
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    for (int i=0; i<n; i++) if (arr[i] > 1) {
      cout << "Case #" << tc << endl << 0 << endl;
      return;
    }

    int i = 0;

    for (int i=1; i*i<n; i++) {
      int j = n/i;
    }

    cout << "Case #" << tc << endl << n << endl;
    return;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
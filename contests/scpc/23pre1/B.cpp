#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 1000001;


int n,d;



void solve(int tc) {
    cin >> n >> d;

    vector<int> pos;
    vector<int> neg;

    int pt = 0;

    for (int i=0; i<n; i++) {
      int x; cin >> x;
      if (x > 0) pos.push_back(x);
      else if (x < 0) neg.push_back(-x);
      else pt++;
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    int ans = 0;

    for (int i=0; i<pos.size(); i++) {
      if (pos[i] > d) break;
      int idx = upper_bound(neg.begin(), neg.end(), d - pos[i]*2) - neg.begin();
      ans = max(ans, i+1 + idx);
    }

    for (int i=0; i<neg.size(); i++) {
      if (neg[i] > d) break;
      int idx = upper_bound(pos.begin(), pos.end(), d - neg[i]*2) - pos.begin();
      ans = max(ans, i+1 + idx);
    }

    cout << "Case #" << tc << endl;
    cout << ans + pt << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
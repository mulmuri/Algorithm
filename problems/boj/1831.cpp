#include <bits/stdc++.h>
using namespace std;

const int SIZE = 50;


int n;
map<int,int> mp;

int main() {
  cin >> n;
  for (int i=0; i<n; i++) {
    int x; cin >> x;
    mp[x]++;
  }

  int ans = 0;
  for (auto it : mp) {
    if (it.first == it.second) {
      ans = max(ans, it.first);
    }
  }

  if (!ans && mp[0]) {
    cout << -1 << endl;
    return 0;
  }

  cout << ans << endl;
}
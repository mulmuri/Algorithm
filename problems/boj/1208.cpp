#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

const int SIZE = 1000000;

#define int long long


int n, s, m;
int arr[SIZE];
int narr[SIZE];
int cnt;

map<int,int> st,nst;




int32_t main() {
  st[0] = 1;
  nst[0] = 1;

  cin >> n >> s;

  if (n == 1) {
    cin >> arr[0];
    if (arr[0] == s) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }

  m = n - n/2;
  n = n/2;




  for (int i=0; i<n; i++) {
    cin >> arr[i];
  }

  for (int i=0; i<m; i++) {
    cin >> narr[i];
  }

  {
    int cnt = 0;
    for (int i=1; i<(1<<n); i++) {
      int sum = 0;

      for (int j=0; j<n; j++) {
        if (i & (1<<j)) {
          sum += arr[j];
        }
      }

      st[sum]++;
    }
  }

  {
    int cnt = 0;
    for (int i=1; i<(1<<m); i++) {
      int sum = 0;

      for (int j=0; j<m; j++) {
        if (i & (1<<j)) {
          sum += narr[j];
        }
      }

      nst[sum]++;
    }
  }

  for (auto it = st.begin(); it != st.end(); it++) {
    int key = it->first;
    int val = it->second;

    int target = s - it->first;

    if (nst.find(target) != nst.end()) {
      cnt += val * nst[target];
    }

  }

  if (s == 0) {
    cnt--;
  }

  cout << cnt << endl;
}
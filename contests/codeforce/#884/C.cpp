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

/*

마이너스가 홀수개 -> 다 지워버릴 수 있음
마이너스가 짝수개 -> 가장 작은 것만 남기고 다 지워버릴 수 있음
플러스가 

가장 왼쪽과 오른쪽의 마이너스는 지워버릴 수 있음


1 4 1 -1 -1 5

3 2 1 4 5

5개
1개


5 2 1 4 3


5
2
1
3
4



4
2
1
3

4 2 1 3 : 1+2+1+1=5
2 1 3 4 : 1+2+1+1=5


5 2 1 3 4 : 8


1 4 7 1 1 8

7 1 1 1 1 8

positive


*/


void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];

    for (int i=1; i<=n; i++) {
      if (arr[i] < 0) {
        arr[i] = 0;
      } else {
        break;
      }
    }

    for (int i=n; i>0; i--) {
      if (arr[i] < 0) {
        arr[i] = 0;
      } else {
        break;
      }
    }

    for (int i=1; i<=n; i++) {
      if (arr[i] != arr[i-1]) {

      }
    }

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
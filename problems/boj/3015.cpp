#include<bits/stdc++.h>
using namespace std;

const int SIZE = 500001;
typedef long long ll;


int n;
int arr[SIZE];
ll ans;
vector<int> stk;

int main() {
  cin >> n;

  for (int i=0; i<n; i++) cin >> arr[i];

  for (int i=0; i<n; i++) {
    
    int e = arr[i];
    while (stk.size() != 0 && stk.back() < e) stk.pop_back();

    if (stk.size() != 0 && stk.back() != e) {
      int tmp = stk.back();
      stk.pop_back();

      while (stk.size() != 0 && stk.back()) stk.pop_back();
      stk.push_back(tmp);
    }
    stk.push_back(e);

    ans += stk.size();
    cout << stk.size() <<' ';
  }

  cout << ans;
}
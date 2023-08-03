#include <iostream>
using namespace std;

const int SIZE = 1000000;


int n, s;
int arr[SIZE];


int main() {
  cin >> n >> s;

  for (int i=0; i<n; i++) {
    cin >> arr[i];
  }

  int cnt = 0;
  for (int i=1; i<(1<<n); i++) {
    int sum = 0;

    for (int j=0; j<n; j++) {
      if (i & (1<<j)) {
        sum += arr[j];
      }
    }

    if (sum == s) {
      cnt++;
    }
  }

  cout << cnt << endl;
}
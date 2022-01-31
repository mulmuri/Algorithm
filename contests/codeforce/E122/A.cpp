#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
#define SIZE 200001


int n;
int arr[SIZE];

void solve() {
    cin >> n;
    if (n%7 == 0) {
        cout << n << endl;
        return;
    }
    for (int i=0; i<10; i++) {
        if (((n/10)*10+i) % 7 == 0) {
            cout << (n/10)*10+i << endl;
            return;
        }
    }
}


int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
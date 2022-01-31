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
    string s;
    cin >> s;
    n = s.size();

    int a = 0, b = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '0') a++;
        else b++;
    }

    if (a == b) cout << a-1 << endl;
    else cout << min(a,b) << endl;
}


int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
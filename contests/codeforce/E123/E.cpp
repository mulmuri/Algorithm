#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'

#define SIZE 200001


int n;

void solve() {
    cin >> n;
    string s; cin >> s;
    int a, b, lv;

    int r = 0, d = 0;
    
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'R') r++;
        else d++;
    }

    if ((d == 0) || (r == 0)) {
        cout << n << endl;
        return;
    }

    int k = 0;
    for (int i=1; i<s.size(); i++) {
        if (s[i] != s[i-1]) {
            k = i;
            break;
        }
    }
    
    reverse(s.begin(), s.end());

    a = 0;
    lv = 0;
    for (int i=0; i<s.size()-k; i++) {
        if (s[i] == 'R') lv++;
        else a += lv;
    }

    b = 0;
    lv = 0;
    for (int i=0; i<s.size()-k; i++) {
        if (s[i] == 'D') lv++;
        else b += lv;
    }

    cout << n*n - (n-1)*k - (a + b) << endl;
}


int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
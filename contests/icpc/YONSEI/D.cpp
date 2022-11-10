#include <bits/stdc++.h>
using namespace std;



int n;
string s;

int main() {
    cin >> n >> s;
    if (n%2 == 1) {
        cout << -1;
        return 0;
    }

    int lv = 0;
    int ans = 0;
    for (auto e: s) {
        if (e == '(') lv++;
        else lv--;
        ans = max(ans, lv);
    }

    cout << ans;
}
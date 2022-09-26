#include <bits/stdc++.h>
using namespace std;



string s,t;


int dpf(int y, int x, int bit) {
    if (y == -1 && x == -1) return 0;
    if (dp[y][x] != -1) return dp[y][x];

    int y1 = y, x1 = x;
    while (--y1 != -1 && t[y1] == bit);

}


int main() {
    cin >> s >> t;
    int i = s.size(), j = t.size();
    while ()
    
}
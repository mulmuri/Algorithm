#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 300001;


string s;

int32_t main() {
    fastio;
    
    cin >> s;
    for (int i=0; i<3; i++) {
        int cnt = 0;
        for (int j=0; j<3; j++) if (s[i] == s[j]) cnt++;
        if (cnt == 1) {
            cout << s[i];
            return 0;
        }
    }
    cout << -1;

}
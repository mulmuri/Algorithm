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


int n;
string s;

int32_t main() {
    fastio;
    
    cin >> n >> s;

    if (n == 2 && s == "BA") {
        cout << "No";
        return 0;
    }

    cout << ((s[0] == 'A' && s[n-1] == 'B') ? "No" : "Yes");
}
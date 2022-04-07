#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 300001;



long long n;

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) {
        cin >> n;
        if (n%2 == 1) cout << "Odd" << endl;
        else if (n%4 == 0) cout << "Even" << endl;
        else cout << "Same" << endl;
    }
    
}
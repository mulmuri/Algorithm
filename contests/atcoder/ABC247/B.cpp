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



int n;

pair<string, string> arr[SIZE];

int32_t main() {
    fastio;

    map<string, int> mp;
    
    cin >> n;
    for (int i=1; i<=n; i++) {
        string a,b; cin >> a >> b;
        arr[i] = {a,b};
        mp[a]++; mp[b]++;
    }

    for (int i=1; i<=n; i++) {
        auto[a, b] = arr[i];
        if (mp[a] >= 2 && mp[b] >= 2) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";

}
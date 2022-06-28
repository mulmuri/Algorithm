#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;
typedef pair<int,int> pii;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200001;


int n;


void solve() {
    cin >> n;
    vector<int> arr;
    if (n == 3) {
        for (int i=1; i<=n; i++) {
            int c; cin >> c;
            arr.push_back(c);
        }
        sort(arr.begin(), arr.end());

        if (find(arr.begin(), arr.end(), arr[0]+arr[1]+arr[2]) != arr.end()) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;        
    }

    for (int i=1; i<=n; i++) {
        int c; cin >> c;
        if (c != 0) arr.push_back(c);
    }

    int sz = arr.size();
    sort(arr.begin(), arr.end());


    if (sz == n && sz == 4) {
        if ((arr[0] + arr[3] == 0) && (arr[1] + arr[2] == 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }

    if (sz > 2) cout << "NO" << endl;
    else if (sz == 2) {
        if (arr[0] + arr[1] == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else if (sz < 2) {
        cout << "YES" << endl;
    }
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
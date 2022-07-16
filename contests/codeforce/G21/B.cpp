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
int arr[SIZE];
int flag;


void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];

    flag = 0;
    for (int i=1; i<=n; i++) {
        if (arr[i] != 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        cout << 0 << endl;
        return;
    }

    flag = 0;
    for (int i=1; i<=n; i++) {
        if (arr[i] == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        cout << 1 << endl;
        return;
    }

    int cnt = 0;    
    for (int i=1; i<=n; i++) {
        if (arr[i-1] == 0 && arr[i] != 0) cnt++;
    }
    if (cnt > 1) cout << 2 << endl;
    else cout << 1 << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
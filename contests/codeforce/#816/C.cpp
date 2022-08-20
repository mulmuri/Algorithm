#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200001;


int n,m;
int arr[SIZE];


int getv(int i, int j) {
    int idx = min(i, n-j+1);

    int ret = idx*(idx-1);
    ret += (n-1-(idx-1)*2)*idx;
    return ret;
}


void solve() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> arr[i];

    int cur = 0;
    for (int i=1; i<=n; i++) cur += i*(n-i+1);

    for (int i=2; i<=n; i++) if (arr[i-1] == arr[i]) cur -= getv(i-1, i);
    
    while (m--) {
        int i,x; cin >> i >> x;

        if (i != 1) {
            if (arr[i-1] != arr[i] && arr[i-1] == x) cur -= getv(i-1,i);
            if (arr[i-1] == arr[i] && arr[i-1] != x) cur += getv(i-1,i);
        }

        if (i != n) {
            if (arr[i+1] != arr[i] && arr[i+1] == x) cur -= getv(i,i+1);
            if (arr[i+1] == arr[i] && arr[i+1] != x) cur += getv(i,i+1);
        }

        arr[i] = x;

        cout << cur << endl;
    }

}

int32_t main() {
    fastio;

    //int t; cin >> t;
    solve();
}
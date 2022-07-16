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


int n,q;
int arr[SIZE];


void solve() {
    cin >> n >> q;
    for (int i=0; i<n; i++) cin >> arr[i];
    reverse(arr, arr+n);

    int cnt = 0;
    int now = 0;
    int idx;

    int flag = 0;

    string ans;

    for (int i=0; i<n; i++) {
        if (flag == 0) {
            if (now < arr[i]) now++;
            ans += '1';

            if (now == q) flag = 1;
        } else {
            if (q >= arr[i]) ans += '1';
            else ans += '0';
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
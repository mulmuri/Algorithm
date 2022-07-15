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
string a,b;




void solve2() {

}

void solve() {
    cin >> n >> a >> b;
    string c(a);
    int cnt;
    int flag;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (a[0] != b[0] || a[n-1] != b[n-1]) {
        cout << -1 << endl;
        return;
    }

    int ans = INF;

    cnt = 0;
    flag = false;

    for (int i=1; i<n-1; i++) {
        if (flag) {
            a[i] = ((a[i] == '1') ? '0' : '1');
            cnt++;
            if (a[i] != b[i]) cnt++;
            if (a[i-1] == a[i+1]) flag = false;

        } else {
            if (a[i] != b[i]) {
                a[i] = ((a[i] == '1') ? '0' : '1');
                cnt++;
                if (a[i-1] == a[i+1]) flag = true;
            }
        }
    }

    ans = min(ans, cnt);

    for (int i=0; i<n; i++) a[i] = c[i];

    cnt = 0;
    flag = false;

    for (int i=1; i<n-1; i++) {
        if (flag) {
            a[i] = ((a[i] == '1') ? '0' : '1');
            cnt++;
            if (a[i] != b[i]) cnt++;
            if (a[i-1] == a[i+1]) flag = false;

        } else {
            if (a[i] != b[i]) {
                a[i] = ((a[i] == '1') ? '0' : '1');
                cnt++;
                if (a[i-1] == a[i+1]) flag = true;
            }
        }
    }

    ans = min(ans, cnt);

    if (flag == false) cout << ans << endl;
    else cout << -1 << endl;




}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
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


int sa,sb;
string a,b;



void solve() {
    cin >> sa >> sb >> a >> b;

    if (!equal(a.end()-sb+1, a.end(), b.begin()+1, b.end())) {
        cout << "NO" << endl;
        return;
    }

    int sum = 0;
    for (int i=0; i<sa-sb+1; i++) sum += a[i]-'0';
    if (b[0] != a[sa-sb] && (sum == 0 || sum == sa-sb+1)) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
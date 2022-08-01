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


int n,h,w;
int arr[SIZE];


void solve() {
    cin >> n >> h >> w;
    int time1 = h*60 + w;
    int ans = INF;

    for (int i=1; i<=n; i++) {
        int a,b; cin >> a >> b;
        int time2 = a*60+b;


        ans = min(ans, (time2 - time1 + 24*60)%(24*60));
    }

    cout << ans/60 <<' '<< ans%60 << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
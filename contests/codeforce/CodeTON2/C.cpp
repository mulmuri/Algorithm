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


int n,m;
int arr[SIZE];


void solve() {
    cin >> n >> m;
    for (int i=1; i<=m; i++) cin >> arr[i];
    sort(arr+1, arr+m+1);

    vector<int> l;
    for (int i=2; i<=m; i++) l.push_back(arr[i] - arr[i-1] - 1);
    l.push_back(arr[1] + n - arr[m] - 1);
    sort(l.begin(), l.end(), greater<>());

    int d = 0;
    int ans = 0;

    //for (auto e: l) cout << e <<' '; cout << endl;

    for (auto e: l) {
        int newe = e - 2*d-1;
        if (newe == 0) newe++;
        ans += max(newe, (int)0);
        d+=2;
    }

    cout << n - ans << endl;
}


int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
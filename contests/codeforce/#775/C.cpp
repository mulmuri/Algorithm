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
const int SIZE = 100001;


int n,m;
vector<int> row[SIZE];
vector<int> col[SIZE];

void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        int t; cin >> t;
        row[t].push_back(j);
        col[t].push_back(i);
    }

    int ans = 0;

    for (int i=1; i<SIZE; i++) {
        sort(row[i].begin(), row[i].end());
        int accum = 0;
        for (int j=1; j<row[i].size(); j++) {
            accum += (row[i][j] - row[i][j-1]) * j;
            ans += accum;
        }
        //if (accum) cout << i <<' '<< accum << endl;
    }
    for (int i=1; i<SIZE; i++) {
        sort(col[i].begin(), col[i].end());
        int accum = 0;
        for (int j=1; j<col[i].size(); j++) {
            accum += (col[i][j] - col[i][j-1]) * j;
            ans += accum;
        }
        //if (accum) cout << i <<' '<< accum << endl;
    }

    cout << ans;
}

int32_t main() {
    fastio;

    solve();
}
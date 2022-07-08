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


// 1 2 4 3



int n;
int arr[SIZE];
int istwo[SIZE];
int used[SIZE];

void solve() {
    cin >> n;
    fill(used, used+n+1, 0);

    cout << 2 << endl;
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j*=2) {
            if (used[j] == 0) {
                used[j] = 1;
                cout << j <<' ';
            }
        }
    }
    for (int i=1; i<=n; i++) if (used[i] == 0) cout << i <<' ';
    cout << endl;
}



int32_t main() {
    fastio;

    for (int i=1; i<SIZE; i<<=1) istwo[i] = 1;

    int t; cin >> t;
    while (t--) solve();
}
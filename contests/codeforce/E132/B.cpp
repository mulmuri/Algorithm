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
int pfl[SIZE];
int pfr[SIZE];


void solve() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> arr[i];

    for (int i=1; i<=n; i++) pfl[i] = pfl[i-1] + max((int)0, arr[i-1] - arr[i]);
    for (int i=n; i; i--) pfr[i] = pfr[i+1] + max((int)0, arr[i+1] - arr[i]);

    while (m--) {
        int s,t; cin >> s >> t;
        if (s < t) {
            cout << pfl[t] - pfl[s] << endl;
        } else {
            cout << pfr[t] - pfr[s] << endl;
        }
    }

}

int32_t main() {
    fastio;

    solve();
}
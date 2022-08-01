#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
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



void solve() {
    set<int> st;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];

    for (int i=n; i; i--) {
        if (st.find(arr[i]) == st.end()) st.insert(arr[i]);
        else {
            cout << i << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
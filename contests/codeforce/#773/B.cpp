#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define int long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define MOD 998244353
#define INF 2e9
#define SIZE 200001



int n;  
int arr[SIZE];

void solve() {
    cin >> n;
    set<int> st;

    for (int i=1; i<=n; i++) {
        int c; cin >> c;
        st.insert(c);
    }

    int r = st.size();
    for (int i=1; i<=r; i++) cout << r <<' ';
    for (int i=r+1; i<=n; i++) cout << i <<' ';
    cout << endl;
}


int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
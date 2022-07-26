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
int arr[SIZE];


void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    
    int left, right;
    for (left=1; left<n; left++) if (arr[left+1] == 0) break;
    for (right=n; right; right--) if (arr[right-1] == 0) break;


    cout << max((int)0, right - left) << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
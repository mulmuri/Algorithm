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

bool hasValue(int left, int right) {
    cout << "? " << left <<' '<< right << endl;
    for (int i=left; i<=right; i++) cin >> arr[i];
    for (int i=left; i<=right; i++) if (i == arr[i]) return 1;
    return 0;
}


void solve() {
    cin >> n;

    int left = 1, right = n;
    while (left+1 < right) {
        int mid = (left + right)/2;

        if (hasValue(left, mid)) right = mid;
        else left = mid;
    }
    cout << "! " << right << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
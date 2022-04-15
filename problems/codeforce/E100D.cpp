#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 200001;

int n;
int arr[SIZE];



void solve() {
    vector<int> a,b;
    cin >> n;
    int ai = 1;
    for (int i=0; i<n; i++) {
        int bi; cin >> bi;
        b.push_back(bi);
        while (ai < bi) a.push_back(ai++);
        ai = bi +1;
    }
    while (ai <= 2*n) a.push_back(ai++);

    //for (auto e: a) cout << e <<' '; cout << endl;
    //for (auto e: b) cout << e <<' '; cout << endl;

    int ridx = n, lidx = 0;

    for (int i=0; i<n; i++) {
        int res = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + n-i-1;
        ridx = min(ridx, res);
    }

    for (int i=0; i<n; i++) {
        int res = lower_bound(b.begin(), b.end(), a[i]) - b.begin() - i;
        lidx = max(lidx, res);
    }
    //cout << lidx <<' '<< ridx << endl;
    cout << ridx - lidx + 1 << endl;

}

int main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
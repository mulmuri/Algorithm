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



int n,x;
int arr[SIZE];

void solve() {
    cin >> n >> x;
    for (int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);

    multiset<int> target;
    multiset<int> got;

    for (int i=0; i<n; i++) {
        if (target.count(arr[i]) > 0) {
            got.erase(got.find(arr[i]/x));
            target.erase(target.find(arr[i]));
        } else {
            got.insert(arr[i]);
            target.insert(arr[i]*x);
        }

    }

    cout << got.size() << endl;

}


int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
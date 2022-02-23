#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define MOD 998244353
#define INF 2e9
#define SIZE 200001



int abs(int a, int b) {
    return max(a-b, b-a);
}

int n;
pair<int,int> arr[SIZE];

void solve() {
    for (int i=0; i<3; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    for (int i=0; i<2; i++) for (int j=i+1; j<3; j++) {
        if (arr[i].second == arr[j].second) {
            for (int k=0; k<3; k++) {
                if ((k != i) && (k != j)) {
                    if (arr[k].second < arr[i].second) {
                        cout << abs(arr[i].first, arr[j].first) << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << 0 << endl;

}


int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
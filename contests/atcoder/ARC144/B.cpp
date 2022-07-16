#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 300001;


int n,a,b;
int arr[SIZE];



bool opt_func(int val) {
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (arr[i] < val) {
            cnt += (val - arr[i]-1)/a+1;
        } else {
            cnt -= (arr[i] - val)/b;
        }
    }
    return (cnt <= 0);
}

int binary_search(int left, int right) {
    while (left+1 < right) {
        int mid = (left + right)/2;
        if (opt_func(mid)) left = mid;
        else right = mid;
    }
    return left;
}


int32_t main() {
    fastio;
    
    cin >> n >> a >> b;
    for (int i=1; i<=n; i++) cin >> arr[i];
    cout << binary_search(0, 1e9+1);

}
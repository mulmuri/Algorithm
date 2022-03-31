#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 300001;



int n,l,w;
int arr[SIZE];

int32_t main() {
    fastio;
    
    cin >> n >> l >> w;
    for (int i=1; i<=n; i++) cin >> arr[i];

    int cnt = 0;
    int now = 0;

    arr[n+1] = l;

    for (int i=1; i<=n+1; i++) {
        if (arr[i] > now) {
            cnt += (arr[i]-now-1)/w + 1;
        }
        now = arr[i] + w;
    }

    cout << cnt;
}
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


int n,q;
int arr[SIZE];
int pfsum[SIZE];



int32_t main() {
    fastio;

    cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> arr[i];
    sort(arr+1, arr+1+n, greater<>());
    for (int i=1; i<=n; i++) pfsum[i] = pfsum[i-1] + arr[i];

    while (q--) {
        int x,y; cin >> x >> y;
        cout << pfsum[x] - pfsum[x-y] << endl;
    }


}
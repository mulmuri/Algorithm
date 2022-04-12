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



int n;
int arr[SIZE];

int32_t main() {
    fastio;
    
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    arr[0] = -INF; arr[n+1] = INF;

    for (int i=1; i<=n; i++) {
        if (
            ( (arr[i-1] > arr[i]) && arr[i] < arr[i+1] ) ||
            ( (arr[i-1] < arr[i]) && arr[i] > arr[i+1] )
        ) cout << 1 <<' ';
        else cout << 0 <<' ';
        if (arr[i] == arr[i+1]) arr[i] = arr[i-1];
    }
}
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
const int SIZE = 10;


int n, d12, d23, d31;
int arr[SIZE];
int num[SIZE];


void solve() {
    cin >> n >> d12 >> d23 >> d31;

    arr[0] = d12;
    arr[1] = d23;
    arr[2] = d31;
    sort(arr, arr+3);
    if (arr[2] > arr[0] + arr[1]) {
        cout << "NO" << endl;
        return;
    }
    if ((arr[0] + arr[1] + arr[2])%2 == 1) {
        cout << "NO" << endl;
        return;
    }

    if (arr[0] + arr[1] == arr[2]) {
        cout << "YES" << endl;

        if (d12 + d23 == d31) {
            num[0] = 1;
            num[1] = 3;
            num[2] = 2;
        }
        if (d31 + d23 == d12) {
            num[0] = 1;
            num[1] = 2;
            num[2] = 3;
        }
        if (d12 + d31 == d23) {
            num[0] = 3;
            num[1] = 2;
            num[2] = 1;
        }

        cout << num[0] << num[1] << num[2] << endl;
        
        int node = 4;

        for (int i=1; i<=arr[0]; i++) {
            if (i == 1 && i == arr[0]) cout << num[0] <<' '<< num[2] << endl;
            else if (i == 1) cout << num[0] <<' '<< node++ << endl;
            else if (i == arr[0]) cout << num[2] <<' '<< node++ << endl;
        }
        for (int i=1; i<=arr[1]; i++) {
            if (i == 1 && i == arr[1]) cout << num[1] <<' '<< num[2] << endl;
            else if (i == 1) cout << num[1] <<' '<< node++ << endl;
            else if (i == arr[1]) cout << num[2] <<' '<< node++ << endl;
        }

        for (int i=node; i<=n; i++) {
            if (i == node) cout << node <<' '<< 1 << endl;
            else cout << i <<' '<< i-1 << endl;
        }
        return;

    }

    int a = (d12 + d23 - d31)/2;
    int b = (d23 + d12 - d31)/2;
    int c = (d31 + d23 - d12)/2;
    if (a + b + c + 1 > n) {
        cout << "NO" << endl;
        return;
    }

    int node = 5;

    cout << "YES" << endl;
    for (int i=1; i<=a; i++) {
        if (i == 1 && i == a) cout << 1 <<' '<< 4 << endl;
        else if (i == 1) cout << 1 <<' '<< node++ << endl;
        else if (i == a) cout << node++ <<' '<< 4 << endl;
    }

    for (int i=1; i<=b; i++) {
        if (i == 1 && i == b) cout << 2 <<' '<< 4 << endl;
        else if (i == 1) cout << 2 <<' '<< node++ << endl;
        else if (i == b) cout << node++ <<' '<< 4 << endl;
    }

    for (int i=1; i<=c; i++) {
        if (i == 1 && i == c) cout << 3 <<' '<< 4 << endl;
        else if (i == 1) cout << 3 <<' '<< node++ << endl;
        else if (i == c) cout << node++ <<' '<< 4 << endl;
    }

    for (int i=node; i<=n; i++) {
        if (i == node) cout << 4 <<' '<< i << endl;
        else cout << i <<' '<< i-1 << endl;
    }


}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
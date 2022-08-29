#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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


int n,x;

int32_t main() {
    fastio;
    
    cin >> n >> x;

    if (n%2 == 1 && x == (n+1)/2) {
        cout << x <<' ';
        for (int i=2; i<=n; i++) {
            if (i%2 == 0) cout << x+i/2 <<' ';
            else cout << x-i/2 <<' ';
        }
    }

    if (n%2 == 0 && x == n/2) {
        cout << x <<' ';
        for (int i=2; i<=n; i++) {
            if (i%2 == 0) cout << x+i/2 <<' ';
            else cout << x-i/2 <<' ';
        }
    }

    if (n%2 == 0 && x == n/2+1) {
        cout << x <<' ';
        for (int i=2; i<=n; i++) {
            if (i%2 == 0) cout << x-i/2 <<' ';
            else cout << x+i/2 <<' ';
        }
    }

    if (n%2 == 1 && x < (n+1)/2) {
        cout << x <<' ';
        int v = (n+1)/2;

        for (int i=1; i<n; i++) {
            if (i%2 == 0) cout << v+i/2 <<' ';
            else cout << ((v-i/2 <= x) ? v-i/2-1 : v-i/2) <<' ';
        }
    }

    if (n%2 == 1 && x > (n+1)/2) {
        cout << x <<' ';
        int v = (n-1)/2;

        for (int i=1; i<n; i++) {
            if (i%2 == 0) cout << ((v+i/2 >= x) ? v+i/2+1 : v+i/2) <<' ';
            else cout << v-i/2 <<' ';
        }
    }

    if (n%2 == 0 && x < n/2) {
        cout << x <<' ';
        int v = n/2+1;

        for (int i=1; i<n; i++) {
            if (i%2 == 0) cout << v+i/2 <<' ';
            else cout << ((v-i/2 <= x) ? v-i/2-1 : v-i/2) <<' ';
        }
    }

    if (n%2 == 0 && x > n/2+1) {
        cout << x <<' ';
        int v = n/2;

        for (int i=1; i<n; i++) {
            if (i%2 == 0) cout << ((v+i/2 >= x) ? v+i/2+1 : v+i/2) <<' ';
            else cout << v-i/2 <<' ';
        }
    }

    
}
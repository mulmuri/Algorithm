#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998244353;
const int INF = 1e18;
const int SIZE = 101;


int n;
int a[SIZE][SIZE];
int b[SIZE][SIZE];
int c[SIZE][SIZE];


void rotate() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            c[i][j] = a[n+1-j][i];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            a[i][j] = c[i][j];
        }
    }
}

bool test() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i][j] && !b[i][j]) {
                return false;
            }
        }
    }
    return true;
}


int32_t main() {
    fastio;

    cin >> n;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> b[i][j];
        }
    }

    for (int i=0; i<=4; i++) {
        if (test()) {
            cout << "Yes";
            return 0;
        }
        rotate();
    }

    cout << "No";
}
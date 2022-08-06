#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 260;


int n;
int arr[SIZE][SIZE];

int dpmin[SIZE][SIZE];
int dpmax[SIZE][SIZE];



void solve(int tc) {
    int ans = 0;

    cin >> n;
    for (int y=1; y<=n; y++) {
        for (int x=1; x<=n; x++) {
            cin >> arr[y][x];
        }
    }

/*
    for (int r=0; r<=n; r++) {
        for (int c=0; c<=n; c++) {
            dpmax[r][c] = 0;
            dpmin[r][c] = n*n;
        }
    }
*/

    for (int r=1; r<=n; r++) {
        for (int c=1; c<=n; c++) {
            for (int y=r-1; y<=n; y++) {
                dpmax[y][c-1] = 0;
                dpmin[y][c-1] = n*n;
            }
            for (int x=c-1; x<=n; x++) {
                dpmax[r-1][x] = 0;
                dpmin[r-1][x] = n*n;
            }

            for (int y=r; y<=n; y++) {
                for (int x=c; x<=n; x++) {
                    dpmax[y][x] = max(max(dpmax[y-1][x], dpmax[y][x-1]), arr[y][x]);
                    dpmin[y][x] = min(min(dpmin[y-1][x], dpmin[y][x-1]), arr[y][x]);

                    if (dpmax[y][x] - dpmin[y][x] + 1 == (y - r + 1)*(x - c + 1)) ans++;
                }
            }
        }
    }

    cout << "Case #" << tc << endl;
    cout << ans << endl;
}

int32_t main() {
    //fastio;

    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
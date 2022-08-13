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
const int SIZE = 11;


int h1, w1;
int h2, w2;
int arr1[SIZE][SIZE];
int arr2[SIZE][SIZE];

int32_t main() {
    fastio;
    
    cin >> h1 >> w1;
    for (int i=0; i<h1; i++) for (int j=0; j<w1; j++) cin >> arr1[i][j];

    cin >> h2 >> w2;
    for (int i=0; i<h2; i++) for (int j=0; j<w2; j++) cin >> arr2[i][j];

    if (h1 < h2 || w1 < w2) {
        cout << "No";
        return 0;
    }

    for (int r=0; r<(1<<h1); r++) {
        int rcnt = 0;
        for (int i=0; i<(1<<h1); i<<=1) if (r & i) rcnt++;
        if (rcnt != h2) continue;

        for (int c=0; c<(1<<w1); c++) {
            int ccnt = 0;
            for (int i=0; i<(1<<w1); i<<=1) if (c & i) ccnt++;
            if (ccnt != w2) continue;

            int vr = 0, vc = 0;

            for (int r1 = 0, r2 = 0; )

        }
    }



}
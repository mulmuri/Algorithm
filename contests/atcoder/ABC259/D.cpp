#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
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


struct info {
    int x,y,r;
};

int n, sx, sy, ex, ey;
int sidx = -1;
int eidx = -1;
info arr[SIZE];

int vst[SIZE];




bool ismet(int i, int j) {
    int len2 = (arr[i].x - arr[j].x)*(arr[i].x - arr[j].x) + (arr[i].y - arr[j].y)*(arr[i].y - arr[j].y);
    int radsum2 = (arr[i].r + arr[j].r)*(arr[i].r + arr[j].r);
    int raddif2 = (arr[i].r - arr[j].r)*(arr[i].r - arr[j].r);

    if (len2 > radsum2) return false;
    if (len2 < raddif2) return false;
    return true;
}

bool isin(int i, int x, int y) {
    int len2 = (arr[i].x - x)*(arr[i].x - x) + (arr[i].y - y)*(arr[i].y - y);
    int rad2 = arr[i].r * arr[i].r;
    return len2 == rad2;
}

void dfs(int ts) {
    for (int nxt=1; nxt<=n; nxt++) {
        if (ismet(ts, nxt) && vst[nxt] == 0) {
            vst[ts] = 1;
            dfs(nxt);
        }
    }
}

bool solve() {
    if (sidx == -1 || eidx == -1) return false;

    dfs(sidx);
    return vst[eidx];
}

int32_t main() {
    fastio;
    
    cin >> n;
    cin >> sx >> sy >> ex >> ey;
    for (int i=1; i<=n; i++) cin >> arr[i].x >> arr[i].y >> arr[i].r;

    for (int i=1; i<=n; i++) {
        if (isin(i, sx, sy)) {
            sidx = i;
            break;
        }
    }
    for (int i=1; i<=n; i++) {
        if (isin(i, ex, ey)) {
            eidx = i;
            break;
        }
    }
    //cout << sidx <<' '<< eidx << endl;

    cout << (solve() ? "Yes" : "No");

}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
#define SIZE 200001
#define MOD 998244353



int n,m,k,q;
pair<int,int> oper[SIZE];
int arrn[SIZE];
int arrm[SIZE];

long long pow(long long n, long long r) {
    long long ret = 1;
    for (; r; r >>= 1) {
        if (r & 1) ret = ret * n % MOD;
        n = n * n % MOD;
    }
    return ret;
}

void solve() {
    cin >> n >> m >> k >> q;
    for (int i=1; i<=q; i++) cin >> oper[i].first >> oper[i].second;

    int cnt = 0;
    int cntn = 0, cntm = 0;

    for (int i=q; i; i--) {
        if (arrn[oper[i].first] > 0 && arrm[oper[i].second] > 0) continue;

        if (arrn[oper[i].first] == 0) {
            cntn++;
            arrn[oper[i].first]++;
        }
        if (arrm[oper[i].second] == 0) {
            cntm++;
            arrm[oper[i].second]++;
        }

        cnt++;

        if (cntn == n || cntm == m) break;
    }

    for (int i=q; i; i--) {
        arrn[oper[i].first] = 0;
        arrm[oper[i].second] = 0;
    }

    int ans = pow(k, cnt);
    cout << ans << endl;
}

int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
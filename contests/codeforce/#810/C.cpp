#include <bits/stdc++.h>
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


int n,m,k;
int arr[SIZE];


void solve() {
    cin >> n >> m >> k;
    for (int i=1; i<=k; i++) cin >> arr[i];
    if (accumulate(arr+1, arr+1+k, (int)0) < n*m) {
        cout << "No" << endl;
        return;
    }

    {
        int cnt = 0;
        int odd = 0;
        int many = 0;
        for (int i=1; i<=k; i++) {
            if (arr[i] < n*2) continue;
            cnt += arr[i]/n;
            if (arr[i]/n%2 != 0) odd = 1;
            if (arr[i]/n >= 4) many = 1;
        }

        if (m%2 == 0) {
            if (cnt >= m) {
                cout << "Yes" << endl;
                return;
            }
        } else {
            if (odd == 1) {
                if (cnt >= m) {
                    cout << "Yes" << endl;
                    return;
                }
            } else {
                if (many) {
                    if (cnt-1 >= m) {
                        cout << "Yes" << endl;
                        return;
                    }
                }
            }
        }
    }

    swap(n, m);
    {
        int cnt = 0;
        int odd = 0;
        int many = 0;
        for (int i=1; i<=k; i++) {
            if (arr[i] < n*2) continue;
            cnt += arr[i]/n;
            if (arr[i]/n%2 != 0) odd = 1;
            if (arr[i]/n >= 4) many = 1;
        }

        if (m%2 == 0) {
            if (cnt >= m) {
                cout << "Yes" << endl;
                return;
            }
        } else {
            if (odd == 1) {
                if (cnt >= m) {
                    cout << "Yes" << endl;
                    return;
                }
            } else {
                if (many) {
                    if (cnt-1 >= m) {
                        cout << "Yes" << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "No" << endl;

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
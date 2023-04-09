#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 300001;


int n,m;

int a,b,c;
pair<int,int> pa,pb,pc;



void solve() {
    cin >> n >> m;

    cout << "? 1 1" << endl;
    cin >> a;

    if (a+1 > n) {
        cout << "? 1 " << a+1 << endl;
        cin >> b;
        cout << "! " << b+1 <<' '<< a+1 << endl;
        return;
    }

    if (a+1 > m) {
        cout << "? " << a+1 <<" 1"<< endl;
        cin >> b;
        cout << "! " << a+1 <<' '<< b+1 << endl;
        return;
    }

    cout << "? " << a+1 <<" 1" << endl;
    cin >> b;

    if (a == b) {
        cout << "? 1 "<< a+1 << endl;
        cin >> c;
        cout << "! " << c+1 <<' '<< a+1 << endl;
    } else {
        cout << "! " << a+1 << ' '<< b+1 << endl;
    }
}

int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
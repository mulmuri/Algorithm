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
const int SIZE = 200001;


int n;
string s1, s2;

int idx;
int idx1[SIZE];
int idx2[SIZE];



void solve() {
    cin >> n;
    cin >> s1 >> s2;

    string ns1, ns2;
    for (auto e: s1) if (e != 'b') ns1 += e;
    for (auto e: s2) if (e != 'b') ns2 += e;

    if (ns1 != ns2) {
        cout << "NO" << endl;
        return;
    }

    idx = 0;
    for (int i=0; i<n; i++) if (s1[i] != 'b') idx1[idx++] = i;
    idx1[idx] = 0;
    idx = 0;
    for (int i=0; i<n; i++) if (s2[i] != 'b') idx2[idx++] = i;
    idx1[idx] = 0;

//abb
//bac
    for (int i=0; i<ns1.size(); i++) {
        if (ns1[i] == 'a') {
            if (idx1[i] > idx2[i]) {
                cout << "NO" << endl;
                return;
            }
        }
        if (ns1[i] == 'c') {
            if (idx1[i] < idx2[i]) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << ns1 <<' '<< ns2 << endl;
    for (int i=0; i<ns1.size(); i++) cout << idx1[i]; cout << endl;
    for (int i=0; i<ns2.size(); i++) cout << idx2[i]; cout << endl;

    cout << "YES" << endl;

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
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


string s;

int pff[1];
int pf[SIZE];


void solve() {
    cin >> s;
    int left = 0;
    int right = 0;
    int quest = 0;

    int n = s.size();

    for (char e: s) {
        left += (e == '(');
        right += (e == ')');
        quest += (e == '?');
    }

    if (left > n/2 || right > n/2) {
        cout << "NO" << endl;
        return;
    }
    if (left == n/2 || right == n/2) {
        cout << "YES" << endl;
        return;
    }

    int cnt = n/2 - left;

    right = -1;
    for (int i=0; i<n; i++) {
        if (s[i] == '?') {
            if (cnt) {
                s[i] = '(';
                left = i;
                cnt--;
            } else {
                s[i] = ')';
                if (right == -1) right = i;
            }
        }
    }
    swap(s[left], s[right]);

    for (int i=0; i<n; i++) pf[i] = pf[i-1] + ((s[i] == '(') ? 1 : -1);
    int e = *min_element(pf, pf+n);
    cout << ((e == 0) ? "NO" : "YES") << endl;

    

    
}

int32_t main() {
    fastio;


    int t; cin >> t;
    while (t--) solve();
}
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



vector<int> getFail(string& str) {
    vector<int> fail(str.size(), 0);
    for (int i = 1, j = 0; i < (int)str.size(); ++i) {
        while (j > 0 && str[i] != str[j]) {
            j = fail[j-1];
        }
        if (str[i] == str[j]) {
            fail[i] = ++j;
        }
    }
    return fail;
}

vector<int> KMP(string& para, string& target) {
    vector<int> fail = getFail(target);
    vector<int> found;

    for (int i = 0, j = 0; i < (int)para.size(); ++i) {
        while (j > 0 && para[i] != target[j]) {
            j = fail[j-1];
        }
        if (para[i] == target[j]) {
            if (j == (int)target.size()-1) {
                found.push_back(i-target.size()+2);
                j = fail[j];
            } else {
                j++;
            }
        }
    }
    return found;
}



int n,m;

void solve(int tc) {
    string x,y;
    string lefty, righty, newy;
    string newx;

    int l,r, cnt;
    cin >> n >> m >> x >> y;

    int flag = 0;
    for (char e: y) if (e != y[0]) flag = 1;
    if (flag == 0) {
        cnt = 0;
        for (char e: x) if (e == y[0]) cnt++;
        cout << "Case #" << tc << endl;
        cout << ((cnt >= m) ? "YES" : "NO") << endl;
        return;
    }


    l = 0;
    while (y[0] == y[l]) l++;
    r = m-1;
    while (y[m-1] == y[r]) r--;
    
    for (int i=0; i<l; i++) lefty += y[i];
    for (int i=l; i<=r; i++) newy += y[i];
    for (int i=r+1; i<m; i++) righty += y[i];


    cnt = 0;
    l = 0;
    while (cnt != lefty.size()) {
        if (x[l] == lefty[0]) cnt++;
        l++;
    }

    cnt = 0;
    r = n-1;
    while (cnt != righty.size()) {
        if (x[r] == righty[0]) cnt++;
        r--;
    }

    for (int i=l; i<=r; i++) newx += x[i];

    //cout << lefty <<' '<< newy <<' '<< righty << endl;
    //cout << newx << endl;

    if (newy.size() == 0) {
        cout << "Case #" << tc << endl;
        cout << ((l<= r+1) ? "YES" : "NO") << endl;
        return;
    }

    vector<int> ret = KMP(newx, newy);

    cout << "Case #" << tc << endl;
    cout << ((ret.size()) ? "YES" : "NO" ) << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

const int SZ = 27;


vector<string> str, a,b;
int used[SZ];

bool compress() {
    for (int i=0; i<str.size()-1; i++) {
        for (int j=i+1; j<str.size(); j++) {
            if (str[j][0] == str[i][str[i].size()-1]) {
                str[i] = str[i] + str[j];
                str.erase(str.begin() + j);
                return 1;
            }
            if (str[j][str[j].size()-1] == str[i][0]) {
                str[i] = str[j] + str[i];
                str.erase(str.begin() + j);
                return 1;
            }
        }
    }
    return 0;
}

void solve(int tc) {
    int n; cin >> n;
    str.clear();
    a.clear();
    b.clear();
    fill(used, used+SZ, 0);
 
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        if (s[0] == s[s.size()-1]) a.push_back(s);
        else b.push_back(s);
    }
    for (auto e: b) a.push_back(e);

    for (int i=0; i<n; i++) {
        string s = a[i];
        str.push_back(s);
        while (compress());
    }

    string ans;
    for (auto e: str) ans += e;

    used[ans[0]%32] = 1;
    for (int i=1; i<ans.size(); i++) {
        if (ans[i] == ans[i-1]) continue;

        if (used[ans[i]%32]) {
            cout << "Case #"<< tc << ": " << "IMPOSSIBLE" << endl;
            return;
        }
        used[ans[i]%32] = 1;
    }

    cout << "Case #"<< tc << ": " << ans << endl;
}

int32_t main() {
    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
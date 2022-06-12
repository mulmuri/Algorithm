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
vector<string> part1;
vector<string> part2;


void solve() {
    cin >> n;
    cin >> s1 >> s2;


    part1.clear();
    part2.clear();

    int type1 = 0, type2 = 0;
    int before = 0;


    for (int now=0; now<n; now++) {
        if ((type1 == 0) && (s1[now] != 'b')) type1 = s1[now];
        if ((type2 == 0) && (s2[now] != 'b')) type2 = s2[now];

        if ((s1[now] != type1 && s1[now] != 'b') || (s2[now] != type2 && s2[now] != 'b')) {
            string ss1, ss2;

            for (int i=before; i<now; i++) ss1 += s1[i];
            part1.push_back(ss1);

            for (int i=before; i<now; i++) ss2 += s2[i];
            part2.push_back(ss2);

            before = now;
            type1 = type2 = 0;
        }
    }

    string ss1, ss2;

    for (int i=before; i<n; i++) ss1 += s1[i];
    part1.push_back(ss1);
    for (int i=before; i<n; i++) ss2 += s2[i];
    part2.push_back(ss2);

    for (int i=0; i<part1.size(); i++) {
        int type;

        for (auto e: part1[i]) {
            if (e == 'a') {
                type = 'a';
                break;
            }
            if (e == 'c') {
                type = 'c';
                break;
            }
        }

        for (auto e: part1[i]) {
            if (e != 'b' && e != type) {
                cout << "NO" << endl;
                return;
            }
        }

        for (auto e: part2[i]) {
            if (e != 'b' && e != type) {
                cout << "NO" << endl;
                return;
            }
        }

        int cnt1 = 0, cnt2 = 0;
        for (auto e: part1[i]) if (e == type) cnt1++;
        for (auto e: part2[i]) if (e == type) cnt2++;
        if (cnt1 != cnt2) {
            cout << "NO" << endl;
            return;
        }

        int pf1 = 0, pf2 = 0;

        for (int j=0; j<part1[i].size(); j++) {
            if (part1[i][j] == 'b') pf1++;
            if (part2[i][j] == 'b') pf2++;

            if (type == 'c') {
                if (pf1 < pf2) {
                    cout << "NO" << endl;
                    return;
                }
            }

            if (type == 'a') {
                if (pf1 > pf2) {
                    cout << "NO" << endl;
                    return;
                }
            }

        }

    }

    cout << "YES" << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
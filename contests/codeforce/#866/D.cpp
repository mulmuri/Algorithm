#include <bits/stdc++.h>
using namespace std;

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 300001;

/*
4
3 2
5 5
2 2
8 7

 6 25 4 56
= 91 = 13 * 7

log N 개의 방법

 7 * 5
 5 * 2
 2 * 3

2 2
3 2 : 5 2
5 5 : 5 7
8 7 : 13 7

 */

int n;
pair<int,int> rect[SIZE];
map<int,int> maph, mapw;

bool test(int a, int b) {
    return true;
}


void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> rect[i].first >> rect[i].second;

    int sum = 0;
    for (int i=0; i<n; i++) sum += rect[i].first * rect[i].second;

    vector<int> divisors;
    for (int i = 1; i <= sum; i++) {
        if (sum % i == 0 && i*i <= sum) {
            divisors.push_back(i);
        }
    }
    cout << sum << endl;

    for (auto e: divisors) {
        maph.clear(); mapw.clear();

        for (int i=0; i<n; i++) {
            mapw[rect[i].first] = i;
            maph[rect[i].second] = i;
        }

        if (test(e, sum/e)) {
            cout << e <<' '<< sum/e << endl;
        }
    }
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
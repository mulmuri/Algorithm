#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 200001;

int n;
int arr[SIZE];



void solve() {
    string s; cin >> s;
    int cnt = 0;
    for (int i=0; i<s.size(); i++) if (s[i] == 'N') cnt++;
    cout << ((cnt == 1) ? "NO" : "YES") << endl;
}

int main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 300001;



int n;
string s;

int32_t main() {
    fastio;
    
    cin >> n >> s;
    string t = s;
    sort(t.begin(), t.end());

    int l = 0, r = n-1;

    while (true) {
        while (t[l] != s[r]) {
            if (l >= r) break;
            r--;
        }
        while (s[l] == s[r]) {
            if (l >= r) break;
            l++;
        }
        if (l >= r) break;

        if (s[l] > s[r]) {
            swap(s[l], s[r]);
            l++; r--;
        }
    }

    cout << s;
}
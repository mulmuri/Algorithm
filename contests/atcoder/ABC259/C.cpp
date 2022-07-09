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
const int SIZE = 300001;


int n;

string s1,s2;

bool f() {
    int p1 = 0, p2 = 0;
    while (p1 < s1.size() && p2 < s2.size()) {
        if (s1[p1] == s2[p2]) {
            p1++; p2++;
        } else {
            if (p1 < 2) return false;
            if (s2[p2] == s1[p1-1] && s1[p1-1] == s1[p1-2]) p2++;
            else return false;
        }
    }
    while (p2 < s2.size()) {
        if (p1 < 2) return false;
        if (s2[p2] == s1[p1-1] && s1[p1-1] == s1[p1-2]) p2++;
        else return false;
    }
    return true;
}

int32_t main() {
    fastio;
    
    cin >> s1 >> s2;

    cout << (f() ? "Yes" : "No");
}
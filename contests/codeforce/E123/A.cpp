#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define int long long
#define endl '\n'
#define SIZE 200001


int n;
int arr[SIZE];
map<char, int> mp;

void solve() {
    string s; cin >> s;

    for (int i=0; i<6; i++) {
        mp[s[i]] = i;
    }
    if ( (mp['r'] < mp['R']) && (mp['g'] < mp['G']) && (mp['b'] < mp['B']) ) cout << "YES" << endl;
    else cout << "NO" << endl;
}


int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
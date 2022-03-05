#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
#define MOD 998244353
#define INF 1e9
#define SIZE 1000001




int n;
string s;


long long pow[SIZE];


void solve() {
    cin >> n >> s;

    string s1 = s.substr(0, n/2);
    string s2 = s.substr(n - n/2, n/2);

    long long sum = 0;
    for (int i=0, j=s1.size()-1; i<s1.size(); i++, j--) {
        sum += (s1[i] - 'A') * pow[j];
        sum %= MOD;
    }
    reverse(s1.begin(), s1.end());

    if (s.size()%2 == 0) {
        if (s1 <= s2) sum++;
    } else {
        sum *= 26;
        if (s1 <= s2) sum += (s[s1.size()]-'A') + 1;
        else sum += (s[s1.size()]-'A');
    }

    cout << sum % MOD << endl;
}


int main() {
    fastio;

    pow[0] = 1;
    for (int i=1; i<=SIZE/2; i++) pow[i] = (pow[i-1]*26) % MOD;

    int t; cin >> t;
    while (t--) solve();
}
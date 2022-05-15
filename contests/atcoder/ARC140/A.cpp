#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
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


int n, k;
string s;

int32_t main() {
    fastio;
    
    cin >> n >> k >> s;

    int ans = INF;

    for (int i=1; i<=n; i++) {
        if (n%i != 0) continue;

        int cost = 0;

        for (int r=0; r<n/i; r++) {
            map<int,int> freq;
            for (int q=0; q<i; q++) {
                int p = q * n/i + r;
                if (p >= n) cout << "!@#";
                freq[s[p]]++;
            }

            int _max = 0;
            for (auto it=freq.begin(); it != freq.end(); it++) {
                _max = max(_max, it->second);
            }

            cost += (i - _max);
        }

        if (cost > k) continue;
        ans = min(ans, n/i);

    }

    cout << ans;
}
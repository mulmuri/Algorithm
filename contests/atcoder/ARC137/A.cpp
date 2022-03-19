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

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 200001;


long long gcd(long long a, long long b) {
    if (b==0) return a;
    return gcd(b, a%b);
}


long long l,r;
long long ans = 0;

int main() {
    fastio;
    
    cin >> l >> r;
    for (long long i=l; i<=min(r, l+1000); i++) {
        for (long long j=max(l, r-1000); j<=r; j++) {
            if (gcd(i,j) == 1) ans = max(ans, j-i);
        }
    }

    cout << ans;
}
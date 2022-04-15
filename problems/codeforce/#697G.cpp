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

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 200001;



int n;

int dp[SIZE];
int cnt[SIZE];

vector<int> prime;


void solution() {
    int n; cin >> n;
    fill(dp, dp+SIZE, 0);
    fill(cnt, cnt+SIZE, 0);
    for (int i=0; i<n; i++) {
        int c; cin >> c;
        cnt[c]++;
    }

    for (int i=1; i<SIZE; i++) {
        if (cnt[i] == 0) continue;
        for (int j: prime) {
            if (j*j > i) continue;
            if (i%j == 0) {
                dp[i] = max(dp[i], dp[j]);
                dp[i] = max(dp[i], dp[i/j]);
            }
        }
        dp[i] += cnt[i];
    }

    int ans = 0;
    for (int i=1; i<SIZE; i++) ans = max(ans, dp[i]);
    cout << n - ans << endl;
}

bool isPrime(int n) {
    for (int i=2; i*i<=n; i++) {
        if (n%i == 0)
            return 0;
    }
    return 1;
}


int32_t main() {
    
    for (int i=1; i*i<SIZE; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }

    fastio;

    int t; cin >> t;
    while (t--) solution();
}
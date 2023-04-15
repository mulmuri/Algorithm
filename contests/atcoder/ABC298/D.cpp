#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998244353;
const int INF = 1e18;
const int SIZE = 300001;


int Q;
int arr[SIZE];



int power(int x) {
    int v;
    if (x == 0) {
        return 1;
    }
    if (x%2 == 0) {
        v = power(x/2);
        return v * v % MOD;
    } else {
        v = power(x/2);
        return v * v * 10 % MOD;
    }
}



queue<int> q;

int32_t main() {
    fastio;

    int cnt = 0;
    int num = 1;

    cin >> Q;
    vector<int> v;
    q.push(1);

    while (Q--) {
        int t,x;
        cin >> t;
        if (t == 1) {
            cin >> x;
            q.push(x);
            num *= 10;
            num += x;
            num %= MOD;

        } else if (t == 2) {
            int t = q.front();
            q.pop();
            num += (MOD - t * power(q.size()) % MOD);
            num %= MOD;

        } else {
            cout << num % MOD << endl;
        }
    }
}
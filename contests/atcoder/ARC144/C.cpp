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


int n,k;


void f(int st, int len) {
    for (int i=st+k; i<st+k+len/2; i++) cout << i <<' ';
    for (int i=st; i<st+len/2; i++) cout << i <<' ';
}

void f(int st) {
    for (int i=st+k; i<st+k*2; i++) cout << i <<' ';
    for (int i=st; i<=n-k*3; i++) cout << i <<' ';
    for (int i=n-k+1; i<=n; i++) cout << i <<' ';
    for (int i=n-k*3+1; i<st+k; i++) cout << i <<' ';
    for (int i=st+k*2; i<=n-k; i++) cout << i <<' ';

    //for (int i=st+k; i<=n; i++) cout << i <<' ';
    //for (int i=st; i<st+k; i++) cout << i <<' ';
}


int32_t main() {
    fastio;
    
    cin >> n >> k;

    if (n/2 < k) {
        cout << -1;
        return 0;
    }

    int unit = k*2;

    if (n % unit == 0) {
        for (int i=1; i<n; i += unit) f(i, unit);
    } else {
        for (int i=1; i<=(n/unit-1)*unit; i += unit) f(i, unit);
        f((n/unit-1)*unit+1);
    }
}
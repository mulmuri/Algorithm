#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200001;


int n;
int a[SIZE];
int b[SIZE];



void solve() {
    cin >> n;

    for (int i=0; i<n; i++) {
        if (i%2 == 0) {
            a[i] = n*2-1-i;
        } else {
            a[i] = i;
        }
    }

    for (int i=0; i<n; i++) {
        if (i%2 == 0) {
            b[i] = i+2; 
        } else {
            b[i] = n*2-1-i;
        }
    }

    b[n-1] = n*2;

    for (int i=0; i<n; i++) cout << a[i] <<' '; cout << endl;
    for (int i=0; i<n; i++) cout << b[i] <<' '; cout << endl;

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
#define SIZE 200001


int n;
int arr[SIZE];

int hc,dc;
int hm,dm;
int k,w,a;

void solve() {
    cin >> hc >> dc;
    cin >> hm >> dm;
    cin >> k >> w >> a;

    for (int i=0, j=k; i<=k; i++, j--) {
        int c = (hm-1) / (dc + w*i) + 1;
        int m = (hc + a*j - 1) / dm + 1;
        if (c <= m) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}


int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
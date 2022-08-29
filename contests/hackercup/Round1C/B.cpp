#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

const int SIZE = 1001;


int arr[SIZE];

void solve(int tc) {
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> arr[i];
    if (k != 1) {
        cout << "Case #"<< tc << ": " << "IMPOSSIBLE" << endl;
        return;
    }

    int p2 = 0;
    for (int i=0; i<n; i++) p2 += arr[i]*arr[i];
    int q = 0;
    for (int i=0; i<n; i++) q += arr[i];

    if (q == 0) {
        if (p2 == 0)
            cout << "Case #"<< tc << ": " << 0 << endl;
        else    
            cout << "Case #"<< tc << ": " << "IMPOSSIBLE" << endl;
        return;
    }

    if ( (p2 - q*q) % (2*q) == 0)
        cout << "Case #"<< tc << ": " << (p2 - q*q) / (2*q) << endl;
    else
        cout << "Case #"<< tc << ": " << "IMPOSSIBLE" << endl;

}

int32_t main() {
    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
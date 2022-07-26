#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'



const int SIZE = 1000001;

int n,c;
int idx[SIZE];



void solve() {
    cin >> n >> c;
    vector<int> arr;
    for (int i=0; i<n; i++) {
        int t; cin >> t;
        arr.emplace_back(t);
        idx[t] = 1;
    }
    unique(arr.begin(), arr.end());
    sort(arr.begin(), arr.end());
    if (idx[1] == 0) {
        cout << "No" << endl;
        for (int e: arr) idx[e] = 0;
        return;
    }

    for (int i=0; i<arr.size(); i++) {
        for (int j=0; j<i; j++) {
            if (idx[arr[i]/arr[j]] == 0) {
                cout << "No" << endl;
                for (int e: arr) idx[e] = 0;
                return;
            }
        }
    }

    cout << "Yes" << endl;
    for (int e: arr) idx[e] = 0;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long


const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200001;

/*
 배열에 나타나지 않는 가장 작은 원소 i = mex
 i + 1 이 없어야 함

 i 보다 작은 원소들을 건드리지 않으면서 i+1 을 없애야 함


 */

int n;
int arr[SIZE];


void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    set<int> s;
    for (int i=0; i<n; i++) s.insert(arr[i]);

    int c = -1;
    for (int i=0; i<n; i++) {
        if (s.find(i) == s.end()) {
            c = i;
            break;
        }
    }

    if (c == -1) {
        sort(arr, arr+n);

        int flag = 1;
        for (int i=0; i<n; i++) if (arr[i] != i) {
            flag = 0;
            break;
        }
        if (flag) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
        return;
    }

    int ext = c+1;
    if (s.find(ext) == s.end()) {
        cout << "YES" << endl;
        return;
    }

    int l,r;
    for (int i=0; i<n; i++) {
        if (arr[i] == c+1) {
            l = i;
            break;
        }
    }

    for (int i=n-1; i; i--) {
        if (arr[i] == c+1) {
            r = i;
            break;
        }
    }

    for (int i=l; i<=r; i++) arr[i] = c;

    set<int> t;

    for (int i=0; i<n; i++) t.insert(arr[i]);

    int nc = -1;
    for (int i=0; i<n; i++) {
        if (t.find(i) == t.end()) {
            nc = i;
            break;
        }
    }

    if (nc == -1) {
        cout << "YES" << endl;
        return;
    }

    //cout << c <<' '<< nc << endl;
    //for (int i=0; i<n; i++) cout << arr[i] <<' '; cout << endl;

    if (nc == c+1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
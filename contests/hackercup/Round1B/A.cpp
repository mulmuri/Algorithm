#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

const int SIZE = 100001;



int n;
int arr[SIZE];

void solve(int tc) {
    int ans = 0;

    deque<int> dq;

    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int c; cin >> c;
        dq.push_back(c);        
    }

    int cur = 0;
    while (!dq.empty()) {
        if (dq.front() < cur) dq.pop_front();
        else if (dq.back() < cur) dq.pop_back();
        else if (dq.front() <= dq.back()) {
            cur = dq.front();
            dq.pop_front();
            ans++;
        }
        else {
            cur = dq.back();
            dq.pop_back();
            ans++;
        }
    }

    cout << "Case #"<< tc << ": " << ans << endl;
}

int32_t main() {
    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
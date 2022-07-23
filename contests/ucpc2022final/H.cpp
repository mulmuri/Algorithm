#include <bits/stdc++.h>
using namespace std;

#define int long long

const int SIZE = 200001;



int n,m,k;

pair<int,int> a[SIZE];
pair<int,int> b[SIZE];

int32_t main() {
    cin >> n >> m >> k;

    for (int i=0; i<n; i++) {
        int u,v; cin >> u >> v;
        a[i] = {u,i};
        b[i] = {v,i};
    }

    int sum = 0;

    sort(b, b+n, greater<>());
    for (int i=0; i<k; i++) {
        int idx = b[i].second;
        sum += a[idx].first;
        a[idx].first = 0;
    }

    sort(a, a+n, greater<>());
    for (int i=0; i<m; i++) {
        sum += a[i].first;
    }

    cout << sum;
}

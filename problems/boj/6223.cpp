#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 1001;

int val[SIZE];
int adj[SIZE];
int vst[SIZE];

int n;

int main() {
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> val[i];
        adj[i] = val[i];
    }

    sort(val, val+n);

    for (int i=0; i<n; i++) adj[i] = lower_bound(val, val+n, adj[i]) - val;
    


    int ans = 0;

    for (int i=0; i<n; i++) {
        if (vst[i]) continue;

        vector<int> cycle = {};
        for (int j=i; vst[j] == 0; j=adj[j]) {
            vst[j] = 1;
            cycle.push_back(val[j]);
        }

        if (cycle.size() == 1) continue;

        int sum = 0;
        for (auto e: cycle) sum += e;

        sort(cycle.begin(), cycle.end(), greater<>());
        ans += (sum*2 - (cycle[0] + cycle[1]));
    }

    cout << ans;

}
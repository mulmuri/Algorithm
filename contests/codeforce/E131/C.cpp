#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;
typedef pair<int,int> pii;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200001;


int n,m;
int arr[SIZE];
int cnt[SIZE];
int num = 0;

map<int,int> mp;




int opt_func(int time) {
    int cnt = 0;
    for (auto it=mp.begin(); it!=mp.end(); it++) {
        if (it->second > time) cnt += time;
        else cnt += (it->second + (time - it->second)/2);
    }
    cnt += ((n - num)*(time/2));

    return (cnt >= m);
}

int binary_search(int low, int high) {
    while (low+1 < high) {
        int mid = (low+high)/2;
        if (opt_func(mid)) high = mid;
        else low = mid;
    }
    return high;
}


void solve() {
    cin >> n >> m;
    mp.clear();

    for (int i=1; i<=m; i++) {
        int c; cin >> c;
        mp[c]++;
    }
    num = mp.size();

    cout << binary_search(0, m+1) << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
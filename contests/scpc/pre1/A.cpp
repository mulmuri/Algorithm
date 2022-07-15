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
const int SIZE = 200001;


int n;
int dist[SIZE];
pair<int,int> arr[SIZE];



void solve(int tc) {
    cin >> n;
    for (int i=0; i<n; i++) cin >> dist[i];
    for (int i=0; i<n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr+n);

    int ans = 0;
    for (int i=0; i<n; i++) {
        ans += abs(dist[i] - dist[arr[i].second]);
    }

    cout << "Case #" << tc << endl;
    cout << ans << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
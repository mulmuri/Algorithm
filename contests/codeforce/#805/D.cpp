#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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


string s;
int n;
pair<int,int> arr[SIZE];


void solve() {
    cin >> s >> n;
    int sz = s.size();
    for (int i=0; i<sz; i++) arr[i] = {s[i], i};
    sort(arr, arr+sz, greater<>());
    
    int sum = 0;
    for (auto e: s) sum += (e-'a'+1);

    int idx = 0;
    while (sum > n) {
        sum -= (arr[idx].first-'a'+1);
        arr[idx].first = 1000;
        idx++;
    }

    for (int i=0; i<sz; i++) arr[i] = {arr[i].second, arr[i].first};
    sort(arr, arr+sz);
    
    for (int i=0; i<sz; i++) if (arr[i].second != 1000) cout << (char)(arr[i].second);
    cout << endl;
    
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
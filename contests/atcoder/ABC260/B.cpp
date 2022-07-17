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
const int SIZE = 300001;


int n,x,y,z;
tuple<int,int,int> arr[SIZE];
vector<int> ans;

int32_t main() {
    fastio;

    
    cin >> n >> x >> y >> z;
    for (int i=0; i<n; i++) cin >> get<0>(arr[i]);
    for (int i=0; i<n; i++) get<1>(arr[i]) = -i;
    for (int i=0; i<n; i++) cin >> get<2>(arr[i]);

    sort(arr, arr+n, greater<>());

    for (int i=0; i<x; i++) ans.push_back(-get<1>(arr[i]));

    for (int i=x; i<n; i++) arr[i] = {
        get<2>(arr[i]),
        get<1>(arr[i]),
        get<0>(arr[i])
    };

    sort(arr+x, arr+n, greater<>());

    for (int i=x; i<x+y; i++) ans.push_back(-get<1>(arr[i]));
    
    for (int i=x+y; i<n; i++) arr[i] = {
        get<0>(arr[i])+get<2>(arr[i]),
        get<1>(arr[i]),
        0,
    };

    sort(arr+x+y, arr+n, greater<>());

    for (int i=x+y; i<x+y+z; i++) ans.push_back(-get<1>(arr[i]));

    sort(ans.begin(), ans.end());
    for (auto e: ans) cout << e+1 << endl;

}
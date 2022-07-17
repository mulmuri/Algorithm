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


int n,k;
int arr[SIZE];
int idx[SIZE];
int ans[SIZE];

vector<int> lis = {0};
vector<vector<int>> lis_elm = {{0}};

int32_t main() {
    fastio;
    
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> arr[i];
    for (int i=1; i<=n; i++) idx[arr[i]] = i;

    for (int i=1; i<=n; i++) {
        auto found = lower_bound(lis.begin(), lis.end(), arr[i]);
        int idx = found - lis.begin();

        if (found == lis.end()) {
            lis.push_back(arr[i]);
            lis_elm.push_back({arr[i]});
        } else {
            lis[idx] = arr[i];
            lis_elm[idx].push_back(arr[i]);       
        }

        if (lis_elm[idx].size() == k) {
            for (int e: lis_elm[idx]) ans[e] = i;
            lis[idx] = lis[idx-1];
        }
    }

    for (int i=1; i<=n; i++) cout << ((ans[i]) ? ans[i] : -1) << endl;
}
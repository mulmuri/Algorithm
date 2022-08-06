#include <bits/stdc++.h>
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




int n,k;
int arr[SIZE];



void solve(int tc) {
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> arr[i];
    
    int idx = min_element(arr, arr+n) - arr;
    for (int i=1; i<idx; i++) arr[i] = min(arr[i-1], arr[i]);
    for (int i=n-2; i>idx; i--) arr[i] = min(arr[i+1], arr[i]);
    for (int i=0; i<n; i++) arr[i] = min(arr[i], k);

    int num = -accumulate(arr, arr+n, -k*n);

    cout << "Case #" << tc << endl;
    cout << k - arr[idx] <<' '<< num << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
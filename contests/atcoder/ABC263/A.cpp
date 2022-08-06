#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998244353;
const int INF = 1e18;
const int SIZE = 300001;


int n;
int arr[SIZE];

int32_t main() {
    fastio;
    
    for (int i=0; i<5; i++) cin >> arr[i];
    sort(arr, arr+5);
    if (arr[0] == arr[1] && arr[3] == arr[4] && (arr[1] == arr[2] || arr[2] == arr[3])) cout << "Yes";
    else cout << "No";
}
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


int n;
int arr[SIZE];

int32_t main() {
    fastio;
    
    cin >> n;
    cout << n*2 << endl;
    if (n%4 != 0) cout << n%4;
    for (int i=0; i<n/4; i++) cout << 4;
}
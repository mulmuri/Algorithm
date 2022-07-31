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
const int SIZE = 500001;


int n;
int arr[SIZE];

int32_t main() {
    fastio;
    
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];

    int same = 0;
    for (int i=1; i<=n; i++) if (arr[i] == i) same++;

    int isame = 0;
    for (int i=1; i<=n; i++) if (arr[i] != i && arr[arr[i]] == i) isame++;
    cout << same * (same-1)/2 + isame/2;
}
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
pair<int,int> arr[SIZE];

int32_t main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        int tmp; cin >> tmp;
        arr[i] = {tmp, i};
    }
    sort(arr, arr+n);

    



    fastio;
}
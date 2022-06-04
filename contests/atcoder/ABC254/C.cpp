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
pair<int,int> narr[SIZE];

int32_t main() {
    fastio;
    
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        narr[i] = {arr[i], i};
    }
    sort(narr, narr+n);

    int num = 0;

    for (int i=0; i<n; i++) {
        if ((narr[i].second - i) % k != 0) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    
}

/*
3 4 1 3 4
1 3 3 4 4


*/
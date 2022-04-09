#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 300001;



int n;
int arr[SIZE];

int32_t main() {
    fastio;
    
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    arr[n] = -1;

    if (n == 1) {
        if (arr[0] == 0) cout << "Yes";
        else cout << "No";
        return 0;
    }

    int idx = 0;
    if (arr[0] == 0) {
        for (int i=0; i<n; i++) {
            if (i == n-1) {
                idx = i;
                break;
            }
            if (arr[i] == arr[i+1]) {
                idx = i;
                break;
            }
        }
    }
    
    int cnt = 0;
    for (int i=idx; i<n-1; i++) {
        if (arr[i] != arr[i+1]) {
            cnt++;
        }
    }
    if ( arr[n-1] == 0) cnt--;

    if (idx == 0 && cnt == 0 && arr[0] == 1) cout << "No";
    else if (idx >= cnt) cout << "Yes";
    else cout << "No";
}
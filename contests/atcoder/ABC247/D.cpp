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



int q;
pair<int,int> arr[SIZE];

int32_t main() {
    fastio;

    int l = 0;
    int r = 0;
    
    cin >> q;
    while (q--) {
        int c; cin >> c;
        if (c == 1) {
            int a,b; cin >> a >> b;
            arr[r++] = {a, b};            
        } else {
            int a; cin >> a;
            int cnt = 0;
            while (a) {
                if (a >= arr[l].second) {
                    cnt += arr[l].first * arr[l].second;
                    a -= arr[l].second;
                    l++;
                } else {
                    cnt += arr[l].first * a;
                    arr[l].second -= a;
                    break;
                }
            }
            cout << cnt << endl;
        }
    }
}
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

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
\

int32_t main() {
    fastio;
    
    int n; cin >> n;
    string s; cin >> s;

    int k = 0;
    int x = 0, y = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'S') {
            x += dx[k%4];
            y += dy[k%4];
        }  else {
            k++;
        }
    }

    cout << x <<' '<< y;
}
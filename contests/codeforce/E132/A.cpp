#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;
typedef pair<int,int> pii;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 11;


int x;
int arr[SIZE];
int board[SIZE];


void solve() {
    cin >> x;
    for (int i=0; i<=3; i++) board[i] = 0;
    for (int i=1; i<=3; i++) cin >> arr[i];

    board[x] = 1;
    board[arr[x]] = 1;
    board[arr[arr[x]]] = 1;
    //board[arr[arr[arr[x]]]] = 1;
    int sum = board[1] + board[2] + board[3];
    cout << ((sum == 3) ? "YES" : "NO") << endl;

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
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
const int SIZE = 200001;


int a,b;
int arr[SIZE];


void solve() {
    cin >> a >> b;
    for (int i=1; i<=min(a,b); i++) cout << "01";
    if (a >= b) for (int i=1; i<=a-b; i++) cout << '0';
    else for (int i=1; i<=b-a; i++) cout << '1';
    cout << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
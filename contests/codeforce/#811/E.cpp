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


int n;
int arr[SIZE];
vector<int> cand = {0,5};

bool f() {
    for (int i=2; i<=n; i++) if ((arr[i]%5 == 0) || arr[i]%20 != arr[1]%20) return false;
    return true;
}

bool g() {
    for (int i=2; i<=n; i++) if (arr[i] != arr[1]) return false;
    return true;
}


void solve() {
    cin >> n;

    //while (n%10 != 1) n += n%10;
    //cout << "escaped " << n << endl;
    //return;



    for (int i=1; i<=n; i++) cin >> arr[i];

    for (int i=1; i<=n; i++) {
        if (arr[i]%5 != 0) while (arr[i]%10 != 2) arr[i] += arr[i]%10;
        if (arr[i]%10 == 5) arr[i] += 5;
    }


    

    if (f()) cout << "Yes" << endl;
    else if (g()) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
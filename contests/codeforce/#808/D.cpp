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

vector<int> vec[2];


void solve() {
    cin >> n;
    vec[0].clear();
    vec[1].clear();

    int zeros = 0;


    for (int i=1; i<=n; i++) {
        int t; cin >> t;
        if (i == 1 && t == 0) vec[1].push_back(0);
        else {
            if (t == 0) zeros++;
            else vec[1].push_back(t);
        }
    }

    for (int i=0; i<n-1; i++) {
        int flag = 0;
        for (int j=1; j<vec[(i+1)%2].size(); j++) {
            int dif = vec[(i+1)%2][j] - vec[(i+1)%2][j-1];
            if (dif == 0) zeros++;
            else vec[i%2].push_back(dif);
        }
        if (zeros) {
            vec[i%2].push_back(0);
            zeros--;
        }
        sort(vec[i%2].begin(), vec[i%2].end());
        vec[(i+1)%2].clear();
    }
    cout << vec[n%2][0] << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
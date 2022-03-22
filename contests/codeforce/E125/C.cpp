#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl "\n"
#define MOD 998232453
#define INF 1e9
#define SIZE 200001

int n;
string s;
int arr[SIZE];



void solve() {
    cin >> n >> s;
    s = ' ' + s;

    int state = -1;

    int cnt = 0;
    int finished = 0;
    for (int i=1; i<=n; i++) {
        if (state == -1) {
            state = s[i];
            continue;
        }
        if (state == '(') {
            cnt++;
            finished = i;
            state = -1;
            continue;
        }
        if (state == ')') {
            if (s[i] == ')') {
                cnt++;
                finished = i;
                state = -1;
            }
            continue;
        }
    }
    cout << cnt <<' '<< n - finished << endl;
}

int main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();    
}
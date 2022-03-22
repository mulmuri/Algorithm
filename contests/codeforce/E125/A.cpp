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
int arr[SIZE];



void solve() {
    int x,y; cin >> x >> y;
    if (x == 0 && y == 0) {
        cout << 0 << endl;
    } else {
        int v = x*x + y*y;
        for (int i=1; i<=100; i++) {
            if (i*i == v) {
                cout << 1 << endl;
                return;
            }
        }
        cout << 2 << endl;
    }

}

int main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();    
}
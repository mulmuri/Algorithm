#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
#define MOD 998232453
#define INF 1e9


int main() {
    fastio;

    int a,b,c;
    cin >> a >> b >> c;
    for (int i=a; i<=b; i++) {
        if (i%c == 0) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}
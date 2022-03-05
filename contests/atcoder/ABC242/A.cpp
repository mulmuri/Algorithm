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
#define SIZE 200001



int a,b,c,x;

int main() {
    fastio;

    cin >> a >> b >> c >> x;

    if (x <= a) cout << 1;
    else if (x > b) cout << 0;
    else {
        cout << (double) c / (double) (b-a);
    }
}
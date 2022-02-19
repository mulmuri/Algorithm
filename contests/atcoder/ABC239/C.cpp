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

#define y1 Y1
#define y2 Y2


int n;
int arr[SIZE];

int main() {
    fastio;

    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    long long p2 = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
    if (p2 == 2 || p2 == 4 || p2 == 10 || p2 == 16 || p2 == 18 || p2 == 20) cout << "Yes";
    else cout << "No";
}
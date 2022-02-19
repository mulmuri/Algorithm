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

int n;
int arr[SIZE];

int main() {
    fastio;

    long long x; cin >> x;
    if (x >= 0) cout << x/10;
    else cout << (x-9)/10;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
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
    cout << fixed;
    cout.precision(6);

    double x;
    cin >> x;
    cout << sqrt(x * (12800000 + x));
}
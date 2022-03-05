#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
#define MOD 998244353
#define INF 1e9
#define SIZE 1000001

int n;
long long arr[SIZE][10];

int main() {
    fastio;

    cin >> n;

    for (int i=1; i<=9; i++) arr[0][i] = 1;

    for (int i=1; i<n; i++) {
        for (int j=1; j<=9; j++) arr[i][j] = (arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1]) % MOD;
    }

    long long sum = 0;
    for (int i=1; i<=9; i++) sum += arr[n-1][i];
    cout << sum % MOD;
}
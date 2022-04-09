#include <iostream>
using namespace std;

#define int long long


const int SZ = 100;

int arr[SZ];
int arr1[SZ];
int arr2[SZ];
int sum2 = 0;

void solve(int tc) {
    int n; cin >> n;

    for (int i=0; i<min(n, SZ); i++) cout << arr1[i] <<' ';
    for (int i=0; i<n - min(n, SZ); i++) cout << arr2[i] <<' ';
    cout << endl;

    for (int i=0; i<n; i++) cin >> arr[i];

    int sum = 0;
    for (int i=0; i<n; i++) sum += arr[i];
    for (int i=0; i<n - min(n, SZ); i++) sum += arr2[i];

    int i = 1;
    while (sum) {
        if (sum%2 == 1) cout << i <<' ';
        i *= 2;
        sum /= 2;
    }
    cout << endl;

    //cout << "Case #"<< tc << ":\n";
}

int32_t main() {
    arr1[0] = 1;
    for (int i=1; i<SZ; i++) arr1[i] = arr1[i-1] * 2;
    for (int i=0; i<SZ; i++) arr2[i] = i*2+3;

    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
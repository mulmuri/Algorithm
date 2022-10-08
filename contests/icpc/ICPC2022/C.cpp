#include <bits/stdc++.h>
using namespace std;

#define int long long

const int SIZE = 1000001;

int n,m;
int arr[SIZE];


int32_t main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    int m = accumulate(arr, arr+n, (int)0);

    int v = m / n;

    int sum1 = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] < v) {
            sum1 += (v - arr[i]);
        }
    }

    int sum2 = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] > v+1) {
            sum2 += (arr[i] - v-1);
        }
    }

    cout << max(sum1, sum2);
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long
#define endl '\n'
#define SIZE 200001
 
 
int n;
int arr[SIZE];
 
void solve() {
    cin >> n;
    cout << ((1 << n) - 1) << endl;
}
 
 
int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

const int SIZE = 100001;
const int MOD = 1e9+7;


int n;
int arr[SIZE];

long long getRect(long long x, long long y) {
    return x*(x+1)/2 * y*(y+1)/2 % MOD;
}


int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        int x,y; cin >> x >> y;
        arr[n-1-y] = x;
    }

    
}
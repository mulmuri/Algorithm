#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int SZ = 501;

int T,D,W,H;
int ans;

int comb[SZ][SZ];

int f(int l, int t, int d) {
    return comb[l+1 - (t-1)*(d-1)][t];
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd (b, a%b);
}

int main() {
    cin >> T >> W >> H >> D;
    
    for (int i=1; i<=W; i++) {
        for (int j=1; j<=H; j++) {
            
        }
    }


}
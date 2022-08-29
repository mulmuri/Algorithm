#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <cassert>
using namespace std;

#define int long long

const int SIZE = (1<<8);

int rotate(int x, int r) {
    int a = (x << (8 - r));
    int b = (x >> r);
    return ( (a | b) & ((1<<8)-1) );
}

int inst[SIZE];

void solve(int tc) {

    for (int i=1; i<SIZE; i++) {
        int cur = i;
        for (int j=1; j<i; j++) {
            cur = rotate(cur, inst[j]);
            cur ^= j;
        }
        cout << bitset<8>(cur) << endl;

        cin >> inst[i];
        assert(inst[i] != -1);
        if (inst[i] == 0) break;
    }
}

int32_t main() {    
    int a,b; cin >> a >> b;
    cout << bitset<8>(rotate(a,b));
    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
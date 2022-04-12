#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 300001;



int x,y;
int arr[SIZE];

bool flag;



int step3(int c, int row, int col) {
    return c <= row * col;
}

void step2(int b, int c, int row, int col) {
    if (row == 0 || col == 0) return;

    int bx = row,
        by = (b-1)/row + 1;
    if (step3(c, row, col - by))
        flag = true;
}

void step1(int a, int b, int c, int row, int col) {
    int ax = row,
        ay = (a-1)/row + 1;

    step2(b, c, row, col - ay);
    step2(b, c, col - ay, row);
}



void permutation(int depth, int sz) {
    if (depth == sz) {
        step1(arr[0], arr[1], arr[2], x, y);
        step1(arr[0], arr[1], arr[2], y, x);

        return;
    }

    for (int i=depth; i<sz; i++) {
        swap(arr[i],arr[depth]);
        permutation(depth+1, sz);
        swap(arr[i],arr[depth]);
    }

}



int32_t main() {
    fastio;
    
    cin >> x >> y;
    for (int i=0; i<=2; i++) cin >> arr[i];

    permutation(0, 3);

    cout << ((flag) ? "Yes" : "No");

}
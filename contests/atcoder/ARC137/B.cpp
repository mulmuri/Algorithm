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

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 300001;



int n;
int arr[SIZE];
int pf_max[SIZE];
int pf_min[SIZE];



int main() {
    fastio;
    
    cin >> n;
    for (int i=1; i<=n; i++) {
        int c; cin >> c;
        arr[i] = (c == 1) ? 1 : -1;
    }

    int _max = 0, _min = 0, prev;
    
    prev = 0;
    for (int i=1; i<=n; i++) {
        prev = prev + arr[i];
        if (prev < 0) prev = 0;
        _max = max(_max, prev);
    }

    prev = 0;
    for (int i=1; i<=n; i++) {
        prev = prev + arr[i];
        if (prev > 0) prev = 0;
        _min = min(_min, prev);
    }

    cout << _max - _min + 1;

}
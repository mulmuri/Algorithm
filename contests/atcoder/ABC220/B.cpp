#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
#define MOD 998232453
#define INF 1e9


int times(int x, int k) {
    int ret = 1;
    while (k--) ret *= x;
}

int main() {
    fastio;

    int k;
    cin >> k;
    string a,b;
    cin >> a >> b;

    long long na = 0, nb = 0;

    for (int i=0; i<a.size(); i++) {
        na += (a[i] - '0');
        na *= k;
    }

    for (int i=0; i<b.size(); i++) {
        nb += (b[i] - '0');
        nb *= k;
    }

    cout << na * nb / (k*k);
}
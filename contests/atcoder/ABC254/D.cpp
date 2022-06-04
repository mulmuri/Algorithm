#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 300001;


int n;
vector<int> square;
int cnt[SIZE];
int isSquare[SIZE];
int semiSquare[SIZE];


int32_t main() {
    fastio;
    
    cin >> n;

    for (int i=2; i*i<=n; i++) square.push_back(i*i);
    int sz = square.size();

    int idx;
    int sqr = 0;
    for (int i=1; i*i<=n; i++) {
        isSquare[i*i] = 1;
        if (i != 1)
        for (int j=2*i*i; j<=n; j+=i*i) semiSquare[j] = 1;
        sqr++;
        idx = i;
    }

    int i = 1;
    for (int i=1; i<=n; i++) {
        while (idx*idx*i > n) idx--;
        cnt[i] = idx;
    }

    //for (int i=1; i<=n; i++) cout << cnt[i] <<' '; cout << endl;

    int ans = 0;
    ans += sqr*sqr;

    for (int i=1; i<=n; i++) {
        if (semiSquare[i]) continue;
        if (isSquare[i] == 0) {
            ans += cnt[i]*cnt[i];
        }
    }

    //cout << sqr << endl;
    cout << ans;

}


/*
7

7 * i*i <= n
개수 : i개

square 인 수는 특별하게 표시


2 인 것 : i 는 root(n) 부터 내려오면서

1 3 5 7
0 2 4 6

2^8/2

짝수개를 선택 - 1



*/
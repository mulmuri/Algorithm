#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;
typedef pair<int,int> pii;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200;


int n;

int cnt[SIZE];


void solve() {
    cin >> n;
    for (int i='a'; i<='z'; i++) cnt[i] = 0;

    for (int i=0; i<=n*2; i++) {
        string s; cin >> s;
        for (auto e: s) cnt[e]++;
    }

    int flag = 0;

    for (char i='a'; i<='z'; i++) {
        if (cnt[i]%2 != 0) {
            cout << i << endl;
            return;
        }
    }
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}


/*

max mst 에 포함 여부 알 수 있음
나머지는 max mst에 포함되지 않음 ->

1) 나머지를 전부 포함
2) 나머지 중 일부를 포함

한 번 할 때마다 최대 m - n 개가 남음

그 자체로 forest 인 친구는 어떻게 걸러내지


sum = 5
del 3 : 3
del 1 : 2
del 2 : 0


0 1 2 4










*/
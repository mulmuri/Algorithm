#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

typedef long long ll;

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 2001;




/*

1 - n
2 - n-1
...

p1, p3 = 1,2
p1, p5 = 1,3 or 2,4
p4, p5 = ??

1 2 3 4 5 6

2 # # 65? 4 #


1 - 2
1 - 4
2 - 3


1 3 : 1
1 5 : 2
4 5 : -1

x = n+1 --> n/2개
x = n --> n/2 개


1 5
2 4
1 4
2 3

1 6
2 5
3 4

1 5
2 4





1. make line
2. create triangle





a b
b c
c a




*/


int n;
int arr[SIZE];
int ans[SIZE];



/*
1 4 2 5 3 6

3 4 2 5 1 6



P = [1,4,2,5,3,6]

array = [3,4,2,5,1,6]

dist = 







P[1], P[2] = 3
P[1]. P[3] = 


2
2
4
1
1
2
3
2
4

arr : 숫자 i 의 상대 위치


1 4 2 5 3 6
3 4 2 5 1 6

2 5 4 3 6 1



p2 p5 p4 p3 p1 p6

i -> 



1. 숫자들끼리 연결하는 연산
2. P[i], P[j] 사이의 거리를 확인하는 연산





2

2 4 6 5 3 1




*/


void solve() {
    cin >> n;

    if (n == 2) {
        cout << "! 1 2 2 1 " << endl;
        return;
    }

    cout << "+ " << n << endl;
    cout << "+ " << n+1 << endl;

    int ab, ac, bc;
    cout << "? 1 2" << endl;
    cin >> ab;

    arr[1] = 0;
    arr[2] = ab;

    for (int i=2; i<n; i++) {

        cout << "? " << i <<' '<< i+1 << endl;
        cin >> bc;
        cout << "? " << i-1 <<' '<< i+1 << endl;
        cin >> ac;

        int flag = ((arr[i-1] < arr[i]) ? 1 : -1);

        if (ac == ab + bc) { // a b c
            arr[i+1] = arr[i-1] + flag*ac;
        } else if (ab == ac + bc) { // a c b
            arr[i+1] = arr[i-1] + flag*ac;
        } else if (bc == ab + ac) { // c a b
            arr[i+1] = arr[i-1] - flag*ac;
        }

        ab = bc;
    }

    int mind = 0;
    for (int i=1; i<=n; i++) mind = min(mind, arr[i]);
    for (int i=1; i<=n; i++) arr[i] = arr[i] - mind + 1;

    for (int i=1; i<=n; i++) cout << arr[i] <<' '; cout << endl; return;

    cout << "! ";
    for (int i=1; i<=n; i++) cout << ans[i] <<' ';
    for (int i=n; i>=1; i--) cout << ans[i] <<' ';
    cout << endl;
}

int32_t main() {

    int t; cin >> t;
    while (t--) solve();
}
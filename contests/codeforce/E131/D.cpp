#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
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
const int SIZE = 500001;


int n;
int b[SIZE];
int a[SIZE];


// b : 0 2 0 1

// i : 1 2 3 4
// a : 2 1 4 3


/*

2 = 1/0 : 2~4
1 = 2/2 : 1~1
4 = 3/0 : 4~4
3 = 4/1 : 3~4


1/0 : 2~5
2/0 : 3~5
3/1 : 2~3
4/4 : 1~1
5/1 : 3~5


5/2 : 2~

3/4 
5/2


6/1 : 4~6

5/4 : 


5/2 : 2~2
10/2 : 5~5
10/3 : 3~3
12/3 : 4~4


n/1 : (n+2)/2 ~ n;
n/2 : 


n/1 : 




a = i/b


7/2 : 3~3
8/2 : 3~4

8/(2+1)+1 = 3
8/2 : 3~4

11/2 : 5
15/5 : 3~4
9/2 : 4~4


i/p = q 인 p 의 범위 :
i/p = q+1 : i = (q+1)*p + r 보다 큼
i/p = q-1 : i = (q-1)*p + r 보다 작음



i/(q+1) < p <= i/q

8/2 : 3~4
9/2 : 4~4
10/2 : 4~5
11/2 : 5~5

3/3 : 1~1
4/3 : x
5/3 : x
6/3 : 2~2
7/3 : 2~2
8/3 : x
9/3 : 3~3
10/3 : 3~3
11/3 : 3~
12/3 : 4



8/2 : 
8/3 = 2 보다 큼
8/1 = 8 보다 작음

st = i/(p+1) ~ i/p



26/5 : 5~5


i : 1 2 3 4 5
a : 3 5 2 1 4
b : 0 0 1 4 1

12/2 5~6

*/


tuple<int,int,int> arr[SIZE];

void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> b[i];

    for (int i=1; i<=n; i++) {
        if (b[i] == 0) arr[i] = {i+1, n, i};
        else if (b[i] == i) arr[i] = {1,1,i};
        else if (b[i] == 1) arr[i] = {i/2+1, i, i};
        else if (b[i] == 2) arr[i] = {i/(b[i]+1)+1, i/b[i], i};
        else arr[i] = {i/b[i], i/b[i], i};
    }

    sort(arr+1, arr+n+1);
    for (int i=1; i<=n; i++) {
        int idx = get<2>(arr[i]);
        a[idx] = i;
    }

    for (int i=1; i<=n; i++) cout << a[i] <<' ';
    cout << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
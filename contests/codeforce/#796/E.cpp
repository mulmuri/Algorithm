#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
const int SIZE = 200001;


int n,k;

void solve() {
    cin >> n >> k;

    int sum = 0;

    int maxforest;

    string s1, s2;
    for (int i=0; i<k; i++) {
        s1 += '1';
        s2 += '0';
    }

    cout << "? " << s1 << endl;
    cin >> maxforest;

    for (int i=0; i<k; i++) {
        s1[i] = '0';

        cout << "? " << s1 << endl;
        
        int v; cin >> v;
        int diff = maxforest - v;

        if (diff == 0) {
            int test1, test2;

            cout << "? " << s2 << endl;
            cin >> test1;

            s2[i] = '1';
            cout << "? " << s2 << endl;
            cin >> test2;

            sum += (test2 - test1);

            continue;
        } else {
            sum += diff;
        }
        s1[i] = '1';
    }
    
    cout << "! "<< sum;
}

int32_t main() {
    solve();
}

/*

11
0 1 0 0 


영향력 없는 친구를 제거 또는 연결



*/
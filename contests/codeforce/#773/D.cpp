#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define int long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define MOD 998244353
#define INF 2e9
#define SIZE 200001

// bubble sort

int n;
int arr[SIZE];

pair<int,int> ans[SIZE];
int anst[SIZE];


void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    map<int,int> mp;
    for (int i=1; i<=n; i++) {
        if (mp.find(arr[i]) == mp.end()) mp[arr[i]] = 1;
        else mp[arr[i]]++;
    }

    for (auto it=mp.begin(); it != mp.end(); it++) {
        if (it->second%2 != 0) {
            cout << -1 << endl;
            return;
        }
    }

    int virt = 0;

    int idx = 0;

    for (int i=1; i<n; i+=2) {
        int target = arr[i];
        int k;
        for (int j=i+1; j<=n; j++) {
            if (arr[j] == target) {
                k = j;
                break;
            }
        }

        for (int j=1; j<= k-i-1; j++) {
            ans[idx++] = {virt-1 + j + k, arr[i+j]};
        }

        reverse(arr+i+1, arr+k+1);
        virt += (k-i-1)*2;
        anst[i/2] = (k-i)*2;
    }

    cout << idx << endl;
    for (int i=0; i<idx; i++) cout << ans[i].first <<' '<< ans[i].second << endl;
    cout << n/2 << endl;
    for (int i=0; i<n/2; i++) cout << anst[i] <<' ';
    cout << endl;

/*

1 3 1 2 2 3
1 3 3 3 1 2 2 3

1 3 1 2 2 3
1 3 1 3 3 2 2 3 // 1 1 3 2 2 3
1 3 1 3 3 2 2 3 2 2 2 2


4 6

3 2 1 1 2


3 to 6
1 to 2
2 to 4

1 3 1 2 2 3
1 3 3 3 1 2 2 3
1 3 3 3 1 3 3 

1 2 3 1
1 2 3 1 2 2
1 2 3 1 2 3 3 2

1 3 3 3 1 2 2 3

1 3 1 2 2 3
1 3 1 3 3 2 2 3





    for (int i=2; i<=n; i++) {
        if (arr[i] == target) {
            for (int j=1; j<=i-target-1; j++) {
                cout << virt-1 + j+i <<' '<< arr[target+j] << endl;
            }
            reverse(arr+target+1, arr+i+1);
            virt += ((i-target-1)*2);
            target = arr[target+2];
            //for (int k=1; k<=n; k++) cout << arr[k];
            //cout << endl; 
        }
    }
    */
}



int32_t main() {
    int t; cin >> t;
    while (t--) solve();
}
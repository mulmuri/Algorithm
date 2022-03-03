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
#define SIZE 300001



long long n;
long long k;

long long arr[SIZE];
long long pff[1];
long long pf[SIZE];



int main() {
    fastio;
    
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    for (int i=0; i<n; i++) pf[i] = arr[i] + pf[i-1];


    long long ans = 1;

    int MAX = arr[n-1];

    for (int i=2; i<=MAX; i++) {
        long long cnt = 0;
        for (int l=0, r=i; l<=MAX; l+=i, r+=i) {
            int li = upper_bound(arr, arr+n, l) - arr;
            int ri = upper_bound(arr, arr+n, r) - arr;
            if (li == ri) continue;

            cnt += ( (long long)r*(long long)(ri - li) - (pf[ri-1] - pf[li-1]) );
        }

        if (cnt <= k) {
            if (i == MAX) {
                ans = i + (k-cnt)/n;
            } else {
                ans = i;
            }
        }
    }

    cout << ans;
}
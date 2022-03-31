#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 50001
#define INF (long long)1e18

int n;
pair<long long, long long> arr[SIZE];

bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
    long long m1 = max(-a.second, a.first - b.second);
    long long m2 = max(-b.second, b.first - a.second);
    return m1 < m2;
}



int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr, arr+n, cmp);

    long long psum = 0;
    long long ans = -INF;
    for (int i=0; i<n; i++) {
        ans = max(ans, psum - arr[i].second);
        psum += arr[i].first;
    }

    cout << ans;
}
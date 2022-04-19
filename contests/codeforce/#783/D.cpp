#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 200001;

int n;
int arr[SIZE];
int lmin[SIZE];
int sum[SIZE];
int dp[SIZE];

map<int,int> mp;


template<typename T>
struct SegTree{
    int size, start;
    vector<T> arr;

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        arr.resize(start+size);
    }

    void update(int here, T val){
        here += start;
        arr[here] = val;
        while (here){
            here /= 2;
            arr[here] = merge(arr[here * 2], arr[here * 2 + 1]);
        }
    }

    T query(int l, int r){
        l += start;
        r += start;
        T ret = 1;
        while (l <= r){
            if (l % 2 == 1) ret = merge(ret, arr[l++]);
            if (r % 2 == 0) ret = merge(ret, arr[r--]);
            l /= 2; r /= 2;
        }
        return ret;
    }

    T merge(T l, T r) {
        return (l * r) % 1000000007;
    }
};



void solve() {
    cin >> n;

/*
    vector<int> s;
    for(int i=1; i<=n; i++) s.push_back(Q[i]);
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    for(int i=1; i<=n; i++)
        Q[i] = lower_bound(s.begin(), s.end(), Q[i]) - s.begin();
*/


    for (int i=1; i<=n; i++) cin >> arr[i];
    for (int i=1; i<=n; i++) sum[i] = sum[i-1] + arr[i];

    SegTree<int> max_st(n+1);

    for (int i=1; i<=n; i++) {}

}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}
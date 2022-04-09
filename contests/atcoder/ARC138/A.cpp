#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = (int)1e12;
const int SIZE = 300001;



template<typename T>
struct SegTree{
    int size, start;
    vector<T> arr;

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        arr.resize(start+size);
        fill(arr.begin(), arr.end(), INF);
    }

    void update(int here, T val){
        here += start;
        arr[here] = val;
        while (here){
            here /= 2;
            arr[here] = merge(arr[here * 2], arr[here * 2 + 1]);
        }
    }

    int query(int val) {
        int pos = 1;
        while (pos < start) {
            if (val >= arr[pos * 2 + 1]) pos = pos * 2 + 1;
            else pos = pos * 2;
        }
        return pos - start;
    }


    T merge(T l, T r) {
        return min(l, r);
    }
};



int n, k;

int32_t main() {
    //fastio;
/*
    SegTree<int> min_st(6);

    for (int i=0; i<2; i++) {
        int c; cin >> c;
        min_st.update(i, c);
    }

    for (int i=0; i<2; i++) {
        int c; cin >> c;
        cout << min_st.query(c) << endl;
    }
*/

// 찾아야 하는 최솟값의 위치


    cin >> n >> k;

    SegTree<int> min_st(k*2);

    for (int i=0; i<k; i++) {
        int c; cin >> c;
        min_st.update(i, c);
    }
    int _min = min_st.arr[1];

    int ans = INF;
    for (int i=k; i<n; i++) {
        int c; cin >> c;
        if (c <= _min) continue;
        int left = min_st.query(c - 1);
        ans = min(ans, i - left);
    }

    if (ans == INF) cout << -1;
    else cout << ans;
}
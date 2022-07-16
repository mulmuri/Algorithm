#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;

const int MOD = 998232453;
const int INF = 1e9;
const int SIZE = 300001;



template<typename T>
struct MaxSegTree{
    int size, start;
    vector<T> arr;

    MaxSegTree(int n): size(n){
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
        T ret = 0;
        while (l <= r){
            if (l % 2 == 1) ret = merge(ret, arr[l++]);
            if (r % 2 == 0) ret = merge(ret, arr[r--]);
            l /= 2; r /= 2;
        }
        return ret;
    }

    T merge(T l, T r) {
        return max(l, r);
    }
};



template<typename T>
struct MinSegTree{
    int size, start;
    vector<T> arr;

    MinSegTree(int n): size(n){
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

    T query(int l, int r){
        l += start;
        r += start;
        T ret = INF;
        while (l <= r){
            if (l % 2 == 1) ret = merge(ret, arr[l++]);
            if (r % 2 == 0) ret = merge(ret, arr[r--]);
            l /= 2; r /= 2;
        }
        return ret;
    }

    T merge(T l, T r) {
        return min(l, r);
    }
};



int n;
int arr[SIZE];
int idx[SIZE];





int get(int st, int ed, MaxSegTree<int> &max_st, MinSegTree<int> &min_st) {
    if (st == ed) return 0;

    int _max = max_st.query(st, ed);
    if (_max > max(arr[st], arr[ed])) return get(st, idx[_max], max_st, min_st) + get(idx[_max], ed, max_st, min_st);

    int _min = min_st.query(st, ed);
    if (_min < min(arr[st], arr[ed])) return get(st, idx[_min], max_st, min_st) + get(idx[_min], ed, max_st, min_st);

    return 1;
}



void solve() {
    cin >> n;

    MaxSegTree<int> max_st(n+1);
    MinSegTree<int> min_st(n+1);


    for (int i=1; i<=n; i++) {
        cin >> arr[i];
        max_st.update(i, arr[i]);
        min_st.update(i, arr[i]);
        idx[arr[i]] = i;
    }

    cout << get(1, n, max_st, min_st) << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) solve();
}


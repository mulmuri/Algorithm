#include <bits/stdc++.h>
using namespace std;

#define SIZE 100010

#define int long long


template<typename T>
struct SegTree{
    int size, start;
    vector<T> arr;

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        arr.resize(start+size);
    }

    void init(T *src) {
        copy(src, src+size, arr.begin()+start);
        for (int here = (start+size)/2; here; here--) {
            arr[here] = merge(arr[here * 2], arr[here * 2 + 1]);
        }
    }

    void print() {
        for (int here=start; here<start+size; here++) cout << arr[here] <<' ';
        cout << endl;
    }

    void update(int here, int val){
        here += start;
        arr[here] += val;
        while (here){
            here /= 2;
            arr[here] = merge(arr[here * 2], arr[here * 2 + 1]);
        }
    }

    T query(int l, int r){
        if (l > r) return 0;
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
        return l + r;
    }
};



int n;
pair<int,int> arr[SIZE];


int32_t main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        int t; cin >> t;
        arr[i] = {t, i};
    }

    SegTree<int> sum_st(n+2);

    sort(arr+1, arr+1+n);

    for (int i=1; i<=n; i++) sum_st.update(i, 1);

    int cnt = 0;
    int tmp = 0;
    for (int i=1; i<=n; i++) {
        auto[val, idx] = arr[i];
        tmp++;

        cnt += min(sum_st.query(1, idx-1), sum_st.query(idx+1, n));
        if (arr[i+1].first != arr[i].first) {
            sum_st.update(idx, tmp);
            tmp = 0;
        }
        cout << val <<' '<< idx << ' '<< min(sum_st.query(1, idx-1), sum_st.query(idx+1, n)) << endl;
    }

    cout << cnt;    
}
#include<bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

#define int long long

const int SIZE = 500001;



template<typename T>
struct SegTree{
    int size, start;
    vector<T> arr;

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        arr.resize(start+size);
    }

    void print() {
        for (int here=start; here<start+size; here++) cout << arr[here] <<' ';
        cout << endl;
    }

    void update(int here, int val){
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
        return l + r;
    }
};




int n;
int arr[SIZE];
int idx[SIZE];
int ans;

int32_t main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];

    SegTree<int> sum_st(n+1);

    for (int i=1; i<=n; i++) {
        if (idx[arr[i]]) sum_st.update(idx[arr[i]], 0);
        sum_st.update(i, 1);
        ans += sum_st.query(idx[arr[i]]+1, i-1);
        idx[arr[i]] = i;
    }

    cout << ans;



}
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

const int SIZE = 500002;
const int INF = 1e9;


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

tuple<int,int,int> arr[SIZE];
pair<int,int> narr[SIZE];

int a[SIZE];
int b[SIZE];
int c[SIZE];

int main() {
    cin >> n;

    for (int i=1; i<=n; i++) {
        int e; cin >> e;
        get<0>(arr[e]) = i;
    }
    for (int i=1; i<=n; i++) {
        int e; cin >> e;
        get<1>(arr[e]) = i;
    }
    for (int i=1; i<=n; i++) {
        int e; cin >> e;
        get<2>(arr[e]) = i;
    }

    sort(arr+1, arr+1+n);
    for (int i=1; i<=n; i++) narr[i] = {get<1>(arr[i]), get<2>(arr[i])};

    SegTree<int> min_st(n+1);
    for (int i=1; i<=n; i++) min_st.update(i, INF);


    int cnt = 0;

    for (int i=1; i<=n; i++) {
        int idx = narr[i].first;
        int vlu = narr[i].second;

        if (min_st.query(1, idx) > vlu) {
            cnt++;
            min_st.update(idx, vlu);
        }
    }

    cout << cnt;
}
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
#define SIZE 200001



int n,m;
pair<int,int> arr[SIZE];

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




int main() {
    fastio;
    
    cin >> n >> m;
    SegTree<int> max_st(n+1);
    
    for (int i=0; i<m; i++) {
        int a,b; cin >> a >> b;
        arr[i] = {b, -a};
    }

    sort(arr, arr+m);

    for (int i=0; i<m; i++) {
        max_st.update(-arr[i].second, max_st.query(1, -arr[i].second - 1) + 1);
    }

    cout << max_st.query(1, n);
}
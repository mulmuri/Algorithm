// 가로 블록 쌓기

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define SIZE 100001

template<typename T>
struct SegTree{
    int size, start;
    vector<T> arr;
    vector<T> lazy;

    SegTree(int n): size(n) {
        start = 1;
        while (start <= size) start *= 2;
        arr.resize(start+size);
        lazy.resize(start+size);
    }

    void propagate(int node, int ns, int ne){
        if(lazy[node] != 0){
            if(node < start){
                lazy[node*2] = merge(lazy[node*2], lazy[node]);
                lazy[node*2+1] = merge(lazy[node*2+1], lazy[node]);
            }
            arr[node] = max(arr[node], lazy[node]);
            lazy[node] = 0;
        }
    }

    void update(int s, int e, T k) { update(s, e+1, k, 1, 0, start); }
    void update(int s, int e, T k, int node, int ns, int ne) {
        propagate(node, ns, ne);

        if (e <= ns || ne <= s) return;
        if (s <= ns && ne <= e) {
            lazy[node] += k;
            propagate(node, ns, ne);
            return;
        }
        int mid = (ns+ne)/2;
        update(s, e, k, node*2, ns, mid);
        update(s, e, k, node*2+1, mid, ne);
        
        arr[node] = merge(arr[node*2], arr[node*2+1]);
    }

    T query(int s, int e) { return query(s, e+1, 1, 0, start); }
    T query(int s, int e, int node, int ns, int ne){
        propagate(node, ns, ne);
        if (e <= ns || ne <= s) return 0;
        if (s <= ns && ne <= e) return arr[node];
        int mid = (ns+ne)/2;
        return merge(query(s, e, node*2, ns, mid), query(s, e, node*2+1, mid, ne));
    }

    T merge(T l, T r) {
        return max(l, r);
    }
};


int n;

pair<long long, long long> arr[SIZE];


int main(){
    cin >> n;

    for (int i=0; i<n; i++) {
        long long a,b;
        cin >> a >> b;
        arr[i].first = b;
        arr[i].second = b + a - 1;
    }

    vector<long long> s;
    for (int i=0; i<n; i++) {
        s.push_back(arr[i].first);
        s.push_back(arr[i].second);
    }

    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    for (int i=0; i<n; i++) {
        arr[i].first = lower_bound(s.begin(), s.end(), arr[i].first) - s.begin();
        arr[i].second = lower_bound(s.begin(), s.end(), arr[i].second) - s.begin();
    }

    SegTree<long long> lazy_st(n*2);

    for (int i=0; i<n; i++) {
        int h = lazy_st.query(arr[i].first, arr[i].second);
        lazy_st.update(arr[i].first, arr[i].second, h+1);
    }

    cout << lazy_st.query(0, n*2-1);
}

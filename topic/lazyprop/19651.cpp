// 수열과 쿼리 39

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int SIZE = 100001;



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

    void construct(){
        for(int i=start-1; i>0; i--)
            arr[i] = merge(arr[i*2], arr[i*2+1]);
    }

    void propagate(int node, int ns, int ne){
        if(lazy[node] != 0){
            if(node < start){
                lazy[node*2] = merge(lazy[node*2], lazy[node]);
                lazy[node*2+1] = merge(lazy[node*2+1], lazy[node]);
            }
            arr[node] += lazy[node] * (ne-ns);
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
        return l+r;
    }
};


int n,m;
int arr[SIZE];
int dif[SIZE];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];

    SegTree<long long> les_st(n+1);
    for (int i=1; i<n; i++) les_st.arr[les_st.start + i] = arr[i+1] - arr[i];

    cin >> m;
    while (m--) {
        int a,i,j;
        cin >> a >> i >> j;
        if (a == 1) {
            int x,y;
            cin >> x >> y;
        } else {
            cout << les_st.query(i, j) + 1 << endl;
        }
    }
}

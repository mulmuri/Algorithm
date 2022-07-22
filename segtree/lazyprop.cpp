#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


#define int long long

template<typename T>
struct SegTree{
    int size, start;
    vector<T> arr;
    vector<T> lazy;

    SegTree(int n): size(n) {
        start = 1;
        while (start <= size) start *= 2;
        arr.resize(start*2);
        lazy.resize(start*2);
    }

    void init(){
        for(int i=start-1; i>0; i--)
            arr[i] = merge(arr[i*2] + arr[i*2+1]);
    }

    void propagate(int node, int ns, int ne){
        if(lazy[node] != 0){
            if(node < start){
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            arr[node] += lazy[node] * (ne-ns);
            lazy[node] = 0;
        }
    }

    void add(int s, int e, long long k){ add(s, e+1, k, 1, 0, start); }
    void add(int s, int e, long long k, int node, int ns, int ne){
        propagate(node, ns, ne);

        if(e <= ns || ne <= s) return;
        if(s <= ns && ne <= e) {
            lazy[node] += k;
            propagate(node, ns, ne);
            return;
        }
        int mid = (ns+ne)/2;
        add(s, e, k, node*2, ns, mid);
        add(s, e, k, node*2+1, mid, ne);
        
        arr[node] = merge(arr[node*2], arr[node*2+1]);
    }

    T sum(int s, int e){ return sum(s, e+1, 1, 0, start); }
    T sum(int s, int e, int node, int ns, int ne){
        propagate(node, ns, ne);
        if(e <= ns || ne <= s) return 0;
        if(s <= ns && ne <= e) return arr[node];
        int mid = (ns+ne)/2;
        return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
    }

    T merge(T l, T r) {
        return l+r;
    }
};


int n,m,k;

int32_t main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    SegTree<long long> sum_st(n+1);

    for(int i=1; i<=n; i++) {
        int c; cin >> c;
        sum_st.add(i, i, c);
    }

    for(int i=0; i<m+k; i++){
        long long a, b, c, d;
        cin >> a;
        if(a == 1) {
            cin >> b >> c >> d;
            sum_st.add(b, c, d);
        }
        else {
            cin >> b >> c;
            cout << sum_st.sum(b, c) << endl;
        }
    }
}

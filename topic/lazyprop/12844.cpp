#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//XOR

#define endl '\n'

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

    void construct(){
        for(int i=start-1; i>0; i--)
            arr[i] = merge(arr[i*2], arr[i*2+1]);
    }

    void propagate(int node, int ns, int ne){
        if(lazy[node] != 0){
            if(node < start){
                lazy[node*2] ^= lazy[node];
                lazy[node*2+1] ^= lazy[node];
            } else {
                arr[node] ^= lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int s, int e, T k) { update(s, e+1, k, 1, 0, start); }
    void update(int s, int e, T k, int node, int ns, int ne) {
        propagate(node, ns, ne);

        if (e <= ns || ne <= s) return;
        if (s <= ns && ne <= e) {
            lazy[node] = k;
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
        return l ^ r;
    }
};


int n,q;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    SegTree<long long> xor_st(n);

    for (int i=0; i<n; i++) cin >> xor_st.arr[xor_st.start + i];
    xor_st.construct();

    cin >> q;
    while (q--) {
        int a,b,c,d;
        cin >> a;

        if (a == 1) {
            cin >> b >> c >> d;
            xor_st.update(b, c, d);
        } else {
            cin >> b >> c;
            cout << xor_st.query(b, c) << endl;
        }
    }

}

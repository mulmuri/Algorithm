#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

const int SIZE = 100001;



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
                lazy[node*2] = merge(lazy[node*2], lazy[node]);
                lazy[node*2+1] = merge(lazy[node*2+1], lazy[node]);
            }
            arr[node] += lazy[node] * (ne-ns);
            lazy[node] = 0;
        }
    }



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

    void update(int s, int e, int type) {
             if (type == 1) { update1(s, e+1, 1, 0, start); }
        else if (type == 2) { update2(s, e+1, 1, 0, start); }
        else if (type == 3) { update3(s, e+1, 1, 0, start); }
    }

    void update1(int s, int e, 1, 0, start);
    void update2(int s, int e, 1, 0, start);
    void update3(int s, int e, 1, 0, start);

    T getmex() {};



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



int n;

typedef struct {
    int type;
    long long l,r;
} node;

node query[SIZE];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) cin >> query[i].type >> query[i].l >> query[i].r;

    vector<long long> s;
    for (int i=0; i<n; i++) {
        s.push_back(query[i].l);
        s.push_back(query[i].l+1);
        s.push_back(query[i].r);
        s.push_back(query[i].r+1);
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    for (int i=0; i<n; i++) {
        query[i].l = lower_bound(s.begin(), s.end(), query[i].l) - s.begin();
        query[i].r = lower_bound(s.begin(), s.end(), query[i].r) - s.begin();
    }


    SegTree<long long> sum_st(4*n);
    for (int i=0; i<n; i++) {
        int type = query[i].type;
        int l = query[i].l;
        int r = query[i].r;

        sum_st.update(l, r, type);
        cout << s[sum_st.getmex()];
    }

}

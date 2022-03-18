// 괄호 문자열과 쿼리

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

#define SIZE 100001
#define INF 1e9


const int ST_MAX = (1 << 22);

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
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            arr[node] += lazy[node];
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
        if (e <= ns || ne <= s) return INF;
        if (s <= ns && ne <= e) return arr[node];
        int mid = (ns+ne)/2;
        return merge(query(s, e, node*2, ns, mid), query(s, e, node*2+1, mid, ne));
    }

    T merge(T l, T r) {
        return min(l, r);
    }
};



string s;
int n,m;
int arr[SIZE];

int ans = 0;


int main(){
    cin >> s >> m;
    n = s.size();
    s = ' ' + s;
    for (int i=1; i<=n; i++) arr[i] = arr[i-1] + ((s[i] == '(') ? 1 : -1);

    SegTree<int> min_st(n*10);
    for (int i=1; i<=n; i++) min_st.arr[min_st.start + i] = arr[i];
    min_st.construct();


    while (m--) {
        int i; cin >> i;

        if (s[i] == ')') {
            s[i] = '(';
            min_st.update(i, n, 2);
        } else {
            s[i] = ')';
            min_st.update(i, n, -2);
        }

        if (min_st.query(1, n) >= 0 && min_st.query(n,n) == 0) ans++;  

        //for (int i=1; i<=n; i++) cout << min_st.query(i, i) <<' ';
        //cout << endl;
    }

    cout << ans;
}

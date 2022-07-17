#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cassert>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 300001;



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



int n,m;

vector<int> arr[SIZE];
priority_queue<int> pq;
int isinq[SIZE];



int32_t main() {
    fastio;

    pq.push(0);
    isinq[0]++;


    cin >> n >> m;
    int min_r = m+1;

    SegTree<int> sum_st(m+1);

    for (int i=1; i<=n; i++) {
        int l,r; cin >> l >> r;
        arr[l].push_back(r);

        min_r = min(min_r, r);

        isinq[l]++;
        pq.push(l);
    }


    for (int i=1; i<=min_r; i++) {
        isinq[i] = 0;

        while (!isinq[pq.top()]) pq.pop();
        int idx = pq.top();

        sum_st.add(idx-i+1, m-i+1, 1);

        for (int e: arr[i]) {
            pq.push(e);
            isinq[e]++;
        }
    }

    for (int i=1; i<=m; i++) cout << sum_st.sum(i,i) <<' ';
}
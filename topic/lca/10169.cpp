#include <iostream>
#include <vector>
using namespace std;

const int MAXD = 17;
const int SIZE = 100001;

#define endl '\n'

vector<int> adj[SIZE];
vector<int> tree[SIZE];



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



struct LCA {
    int size;
    vector<int> *tree;
    int p[SIZE][MAXD], depth[SIZE];

    LCA(int n, vector<int>* ptree): size(n) {
        tree = ptree;
    };

    void dfs(int t, int d, int q) {
        depth[t] = d;
        for (int n : tree[t])
            if (n != q) {
                p[t][0] = t;
                dfs(t, d + 1, t);
            }
    }
    
    void construct() {
        dfs(1, 0, 0);
        for (int j = 1; j < MAXD; j++)
            for (int i = 1; i < size; i++)
                p[i][j] = p[p[i][j - 1]][j - 1];
    }
    
    int find(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
    
        int depth_diff = depth[a] - depth[b];
        for (int j = MAXD - 1; j >= 0; j--)
            if (depth_diff & (1 << j))
                a = p[a][j];
    
        if (a == b) return a;
    
        for (int j = MAXD - 1; j >= 0; j--)
            if (p[a][j] != p[b][j])
                a = p[a][j], b = p[b][j];
    
        return p[a][0];
    }
};



int mst_cost = 0;

vector<int> tree[];






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



int minw[SIZE];
vector<int> off_queue[SIZE];

void off_dfs(int t, int p) {
    for (int n: tree[t]) {
        
    }
}



int n,q;

/*

mst + 해당 노드의 값 - 저장된 값

mst를 구하는데는 크루스칼이 더 간편




마지막 lazy 쿼리
오프라인 쿼리를 출력하는데 lazy가 필요한가?
진심으로 어이없는게 차피 전구간에 쿼리 날릴거 그냥 현재 값만 갖고 있으면 되는거 아닌가

어떤 node 위치를 지날때 

dfs를 돌며 




*/



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    LCA lca(n+1, adj);
    lca.construct();

    cin >> q;
    while (q--) {
        int a,b; cin >> a >> b;
        cout << lca.find(a,b) << endl;
    }

}
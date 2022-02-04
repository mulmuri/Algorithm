#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int INF = 1e9;


struct NodeMax{
    int s, m, l, r;
    NodeMax() : s(0), m(-INF), l(-INF), r(-INF) { }
    NodeMax operator+(NodeMax &right) {
        NodeMax ret;
        ret.s = s + right.s;
        ret.l = max(l, s + right.l);
        ret.r = max(right.r, r + right.s);
        ret.m = max(r + right.l, max(m, right.m));
        return ret;
    }
};

struct NodeMin{
    int s, m, l, r;
    NodeMin() : s(0), m(-INF), l(-INF), r(-INF) { }
    NodeMin operator+(NodeMin &right) {
        NodeMin ret;
        ret.s = s + right.s;
        ret.l = max(l, s + right.l);
        ret.r = max(right.r, r + right.s);
        ret.m = max(r + right.l, max(m, right.m));
        return ret;
    }
};



struct Node{
    int s, m, l, r;
    Node() : s(0), m(-INF), l(-INF), r(-INF) { }
    Node operator+(Node &right) {
        Node ret;
        ret.s = s + right.s;
        ret.l = max(l, s + right.l);
        ret.r = max(right.r, r + right.s);
        ret.m = max(r + right.l, max(m, right.m));
        return ret;
    }
};

template<typename T>
struct SegTree{
    int size, start;
    vector<T> arr;

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        arr.resize(start+size);
    }

    void update(int here, int val){
        here += start;
        if (arr[here].m == 1) val = -1;
        else if (arr[here].m == -1) val = 1;

        arr[here].s = val;
        arr[here].l = val;
        arr[here].r = val;
        arr[here].m = val;
        while (here){
            here /= 2;
            arr[here] = merge(arr[here * 2], arr[here * 2 + 1]);
        }
    }

    int query(int l, int r){
        l += start;
        r += start;
        Node retL = Node();
        Node retR = Node();
        while (l <= r){
            if (l % 2 == 1) retL = merge(retL, arr[l++]);
            if (r % 2 == 0) retR = merge(arr[r--], retR);
            l /= 2; r /= 2;
        }
        return (retL + retR).m;
    }

    T merge(T l, T r) {
        return l + r;
    }
};

int n,q;
string s;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> q >> s;
    SegTree<NodeMin> st(n+1);

    for (int i=1; i<=n; i++) {
        int val;
        if (s[i-1] == '(') val = 1;
        else val = -1;
        st.update(i, val);
    }

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            
        }
        cout << st.query(l, r) << '\n';
    }

}
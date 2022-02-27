#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
#define MOD 998232453
#define INF 1e9
#define SIZE 200001

int n,m;
int idxp[SIZE];
int idxq[SIZE];

vector<int> adj[SIZE];
vector<int> ans;

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
    
    cin >> n;
    SegTree<int> max_st(n+1);

    for (int i=1; i<=n; i++) {
        int c; cin >> c;
        idxp[c] = i;
    }
    for (int i=1; i<=n; i++) {
        int c; cin >> c;
        idxq[c] = i;
    }

    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j+=i) {
            adj[idxp[i]].push_back(idxq[j]);
        }
        sort(adj[idxp[i]].begin(), adj[idxp[i]].end(), greater<>());
    }

    for (int i=1; i<=n; i++) {
        for (auto e: adj[i]) {
            max_st.update(e, max_st.query(1, e-1) + 1);
        }
    }

    for (int i=1; i<=n; i++) {
        for (auto e: adj[i]) {
            auto it = lower_bound(ans.begin(), ans.end(), e+1);
            if (it == ans.end()) ans.push_back(e+1);
            else ans[it - ans.begin()] = e+1;
        }
    }

    cout << ans.size();

}
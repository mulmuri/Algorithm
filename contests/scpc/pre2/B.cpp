#include <bits/stdc++.h>
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

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        arr.resize(start+size);
    }

    void print() {
        for (int here=start; here<start+size; here++) cout << arr[here] <<' ';
        cout << endl;
    }

    void update(int here, int val){
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
        return l + r;
    }
};


int n;
int arr[SIZE];
vector<int> elm[SIZE];


void solve(int tc) {
    for (int i=1; i<=n; i++) elm[i].clear();

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    SegTree<int> sum_st(n+1);
    for (int i=0; i<n; i++) {
        elm[arr[i]].push_back(i);
        sum_st.update(i, 1);
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        if (elm[arr[i]].size() == 0) continue;
        int r = elm[arr[i]].back();
        elm[arr[i]].pop_back();

        if (r <= i) continue;

        ans += sum_st.query(i+1,r-1) + 1;
        sum_st.update(r, 0);
    }
    
    cout << "Case #" << tc << endl;
    cout << ans << endl;
}

int32_t main() {
    fastio;

    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
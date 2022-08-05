#include<bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

typedef long long ll;
#define int long long

const int SIZE = 100001;


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
        arr[here] += val;
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
pair<int,int> arr[SIZE];
vector<int> varr1[SIZE];
vector<pair<int,int>> varr2[SIZE];
ll ans;


int32_t main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i].first;
    for (int i=0; i<n; i++) cin >> arr[i].second;

    vector<int> s;
    for(int i=0; i<n; i++) s.push_back(arr[i].first);
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    for(int i=0; i<n; i++)
        arr[i].first = lower_bound(s.begin(), s.end(), arr[i].first) - s.begin();
    
    s.clear();
    for(int i=0; i<n; i++) s.push_back(arr[i].second);
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    for(int i=0; i<n; i++)
        arr[i].second = lower_bound(s.begin(), s.end(), arr[i].second) - s.begin();
    
    sort(arr, arr+n);

    for (int i=0; i<n; i++) varr1[arr[i].first].push_back(arr[i].second);

    SegTree<int> sum_st(n+1);

    for (int i=0; i<s.size(); i++) {
        for (int j: varr1[i])
            varr2[i].push_back({j, sum_st.query(0, j-1)});
        for (int j: varr1[i])
            sum_st.update(j, 1);
    }


    fill(sum_st.arr.begin(), sum_st.arr.end(), 0);

    for (int i=0; i<s.size(); i++) {
        for (int j: varr1[i])
            ans += sum_st.query(0, j-1);
        for (auto[j, k]: varr2[i])
            sum_st.update(j, k);
    }

    cout << ans;
}
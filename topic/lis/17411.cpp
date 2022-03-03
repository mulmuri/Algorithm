#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

#define SIZE 1000001
const int MOD = 1e9 + 7;

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
        arr[here] += val;
        arr[here] %= MOD;
        while (here){
            here /= 2;
            arr[here] = merge(arr[here * 2], arr[here * 2 + 1]);
        }
    }

    void update(int here){
        here += start;
        arr[here] = 0;
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
        return (l + r) % MOD;
    }
};

int n;
int arr[SIZE];

vector<int> lis;
vector<list<int>> lis_elm;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    SegTree<int> st_sum(n+1);
    for (int i=0; i<n; i++) cin >> arr[i];

    vector<int> s(n+1);
    for (int i=0; i<n; i++) s[i] = arr[i];
    sort(s.begin(), s.end());

    s.erase(unique(s.begin(), s.end()), s.end());
    for (int i=0; i<n; i++) arr[i] = lower_bound(s.begin(), s.end(), arr[i]) - s.begin() + 1;
    s.clear();

    lis.push_back(0);
    lis_elm.push_back({0});
    st_sum.update(0, 1);

    for (int i=0; i<n; i++) {
        int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
        
        if (idx == lis.size()) {
            lis.push_back(arr[i]);
            lis_elm.push_back({arr[i]});
        } else {
            lis[idx] = arr[i];
            lis_elm[idx].push_front(arr[i]);
        }

        while (lis_elm[idx-1].back() >= arr[i]) {
            st_sum.update(lis_elm[idx-1].back());
            lis_elm[idx-1].pop_back();
        }

        st_sum.update(arr[i], st_sum.query(lis[idx-1], lis[idx]-1));
    }

    cout << lis.size()-1 <<' '<< st_sum.query(lis_elm.back().front(), lis_elm.back().back()) << endl;
}
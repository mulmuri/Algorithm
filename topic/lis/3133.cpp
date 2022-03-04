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


vector<int> cox, coy;
pair<int,int> point[SIZE];



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    SegTree<int> st_sum(n+1);

    for (int i=0; i<n; i++) {
        int x,y;
        cin >> x >> y;
        point[i] = {x,y};
        cox.push_back(x);
        coy.push_back(y);
    }

    sort(cox.begin(), cox.end());
    sort(coy.begin(), coy.end());
    cox.erase(unique(cox.begin(), cox.end()), cox.end());
    coy.erase(unique(coy.begin(), coy.end()), coy.end());

    for (int i=0; i<n; i++) {
        point[i].first = lower_bound(cox.begin(), cox.end(), point[i].first) - cox.begin();
        point[i].second = - (lower_bound(coy.begin(), coy.end(), point[i].second) - coy.begin());
    }

    sort(point, point+n);
    for (int i=0; i<n; i++) arr[i] = -point[i].second + 1;

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

    cout << lis.size()-1 << endl << st_sum.query(lis_elm.back().front(), lis_elm.back().back()) << endl;
}
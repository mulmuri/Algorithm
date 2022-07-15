#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'

typedef long long ll;

const int MOD = 1e9+7;
const int SIZE = 1000001;



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
        return (l + r) % MOD;
    }
};



int n;
int arr[SIZE];

vector<vector<ll>> lis;
vector<ll> lis_top;


int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    for (int i=0; i<n; i++) {
        auto found = lower_bound(lis_top.begin(), lis_top.end(), arr[i]);
        if (found == lis_top.end()) {
            lis_top.push_back(arr[i]);
            lis.push_back({arr[i]});
        } else {
            *found = arr[i];
            lis[found-lis_top.begin()].push_back(arr[i]);
        }
    }

    for (auto lis_set: lis) {
        for (auto lis_elm: lis_set) {
            cout << lis_elm <<' ';
        }
        cout << endl;
    }
}
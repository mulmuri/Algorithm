#include<bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

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




int main() {


}
#include<bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

const int SIZE = 500001;

#define int long long


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
        return max(l, r);
    }
};





int n;
int arr[SIZE];



int32_t main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    SegTree<int> inc_lv2(n+1);
    SegTree<int> inc_lv3(n+1);
    SegTree<int> dec_lv2(n+1);
    SegTree<int> dec_lv3(n+1);
 
    vector<int> s;
    for(int i=0; i<n; i++) s.push_back(arr[i]);
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    for(int i=0; i<n; i++)
        arr[i] = lower_bound(s.begin(), s.end(), arr[i]) - s.begin();

    int flag_inc;
    int flag_dec;

    int _max = arr[0];
    int _min = arr[0];

    for (int i=1; i<n; i++) {

        if (_min < arr[i] && inc_lv2.query(arr[i], arr[i]) == 0)
            inc_lv2.update(arr[i], 2);
        if (max(inc_lv3.query(0, arr[i]-1), inc_lv2.query(0, arr[i]-1)))
            inc_lv3.update(arr[i], max(inc_lv3.query(0, arr[i]-1), inc_lv2.query(0, arr[i]-1)) + 1);
        else if (dec_lv3.query(0, arr[i]-1))
            inc_lv2.update(arr[i], dec_lv3.query(0, arr[i]-1) + 1);

        if (_max > arr[i] && dec_lv2.query(arr[i], arr[i]) == 0)
            dec_lv2.update(arr[i], 2);
        if (max(dec_lv3.query(arr[i]+1, n-1), dec_lv2.query(arr[i]+1, n-1)))
            dec_lv3.update(arr[i], max(dec_lv3.query(arr[i]+1, n-1), dec_lv2.query(arr[i]+1, n-1) + 1));
        else if (inc_lv3.query(arr[i]+1, n-1))
            dec_lv2.update(arr[i], inc_lv3.query(arr[i]+1, n-1) + 1);
        
        _max = max(_max, arr[i]);
        _min = min(_min, arr[i]);

        //cout << "query " << i << endl;
        //inc_lv2.print();
        //inc_lv3.print();
        //dec_lv2.print();
        //dec_lv3.print();
    }

    cout << max(inc_lv3.query(0, n-1), dec_lv3.query(0, n-1));
}
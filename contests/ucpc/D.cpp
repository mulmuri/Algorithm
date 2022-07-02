#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200001;



template<typename T>
struct SegTree{
    int size, start;
    vector<T> arr;

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        arr.resize(start+size);
    }

    void update(int here){
        here += start;
        arr[here] = 1 - arr[here];
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



struct fraction{
    int up, down;
    //__int128 up, down;
    bool operator<(const fraction& ref) const{
        return this->up * ref.down < this->down * ref.up;
    }
    bool operator==(const fraction& ref) const{
        return this->up == ref.up && this->down == ref.down;
    }
};



tuple<int,int,int> query[SIZE];
pair<int,int> Q[SIZE];
vector<fraction> s;
vector<fraction> t;
int isminus[SIZE];



int32_t main() {
    fastio;

    cin >> n;
    for (int i=0; i<n; i++) {
        int a,b,c;
        cin >> Q[i].first;
        if (Q[i].first == 1) {
            cin >> a >> b;
            if (a < 0) isminus[i] = 1;

            fraction tmp;
            tmp.up = -b;
            tmp.down = a;
            s.push_back(tmp);
            t.push_back(tmp);

        } else {
            cin >> c;

            fraction tmp;
            tmp.up = c;
            tmp.down = 1;
            s.push_back(tmp);
            t.push_back(tmp);
        }
    }

    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    for(int i=0; i<n; i++)
        Q[i].second = lower_bound(s.begin(), s.end(), t[i]) - s.begin();

    
    for (int i=0; i<n; i++) {
        cout << Q[i].first <<' '<< Q[i].second << endl;
    }




    SegTree<int> sum_st(n+1);

    int minus = 0;
    for (int i=0; i<n; i++) {
        auto[t, idx] = Q[i];
        if (Q[i].first == 1) {
            sum_st.update(idx);
        } else {
            if (sum_st.query(idx, idx) == 1) {
                cout << 0 << endl;
                continue;
            }
            int ret = sum_st.query(0, idx);
            cout << ((ret + minus)%2 == 0) ? '+' : '-' << endl;
        }
    }

}
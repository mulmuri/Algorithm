#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

typedef long long ll;

const ll MOD = 1000000007;
const int SIZE = 500010;



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



ll fact[SIZE];
ll invf[SIZE];

ll pow(ll a, ll e) {
    ll r = 1, b = a % MOD;
    while (e > 0) {
        if (e & 1)
            r = r * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return r;
}

ll inv(ll x) {
    return pow(x, MOD-2);
}

ll comb(ll n, ll r) {
    return fact[n] * invf[r] % MOD * invf[n-r] % MOD;
}



int n,k;
ll arr[SIZE];
vector<int> lv[SIZE];



void solve(int tc) {
    cin >> n >> k;
    for (int i=0; i<=k; i++) lv[i].clear();
    for (int i=1; i<=n; i++) cin >> arr[i];

    if (k == 1) {
        cout << "Case #" << tc << endl;
        cout << 1 << endl;
        return;
    }

    ll sum = accumulate(arr+1, arr+n+1, (ll)0);

    if (sum == 0) {
        ll psum = 0;
        int cnt = 0;
        for (int i=1; i<=n; i++) {
            psum += arr[i];
            if (psum == 0) cnt++;
        }

        cout << "Case #" << tc << endl;
        cout << comb(cnt, k-1) << endl;
        return;
    }

    if (k == 2) {
        ll psum = 0;
        int cnt = 0;
        for (int i=1; i<=n; i++) {
            psum += arr[i];
            if (psum*2 == sum) cnt++;
        }
        cout << "Case #" << tc << endl;
        cout << cnt << endl;
        return;
    }
    
    ll quo = sum / k;

    if (sum % k != 0) {
        cout << "Case #" << tc << endl;
        cout << 0 << endl;
        return;
    }

    ll psum = 0;
    for (int i=1; i<=n; i++) {
        psum += arr[i];
        if (psum != 0 && psum % quo == 0) lv[psum/quo].push_back(i);
    }
    lv[0] = {0};
    lv[k].clear();
    lv[k].push_back(n);
/*
    for (int i=0; i<=k; i++) {
        cout << i <<": ";
        for (auto j: lv[i]) cout << j <<' ';
        cout << endl;
    }
    cout << endl;
*/
    for (int i=1; i<=k; i++) reverse(lv[i].begin(), lv[i].end());

    SegTree<ll> sum_st(n+1);

    sum_st.update(0, 1);

    for (int i=1; i<=k; i++) {
        for (int j: lv[i]) {
            //cout << j << ": "<< sum_st.query(0, j) << endl;
            sum_st.update(j, sum_st.query(0, j-1));
        }
        for (int j: lv[i-1]) {
            sum_st.update(j, 0);
        }
    }

    cout << "Case #" << tc << endl;
    cout << sum_st.query(n, n) << endl;
}

int32_t main() {
    fastio;

    fact[0] = 1;
    for (int i=1; i<SIZE; i++) fact[i] = fact[i-1] * i % MOD;
    invf[SIZE-1] = inv(fact[SIZE-1]);
    for (int i=SIZE-2; i>=0; i--) invf[i] = invf[i+1] * (i+1) % MOD;

    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}
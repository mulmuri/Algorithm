#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n';


typedef long long ll;
typedef complex<double> base;
const double pi = 3.14159265358979323846264;

void fft(vector<base> &a, bool inv){
    int n = a.size(), j = 0;
    vector<base> roots(n/2);
    for (int i=1; i<n; i++){
        int bit = (n >> 1);
        while (j >= bit){
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if(i < j) swap(a[i], a[j]);
    }
    double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
    for (int i=0; i<n/2; i++){
        roots[i] = base(cos(ang * i), sin(ang * i));
    }

    for (int i=2; i<=n; i<<=1){
        int step = n / i;
        for (int j=0; j<n; j+=i){
            for (int k=0; k<i/2; k++){
                base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
                a[j+k] = u+v;
                a[j+k+i/2] = u-v;
            }
        }
    }
    if (inv) for(int i=0; i<n; i++) a[i] /= n;
}

vector<ll> conv(vector<ll> &v, vector<ll> &w, ll mod){
    int n = 2;
    while (n < v.size() + w.size()) n <<= 1;
    vector<base> v1(n), v2(n), r1(n), r2(n);
    for (int i=0; i<v.size(); i++){
        v1[i] = base(v[i] >> 15, v[i] & 32767);
    }
    for (int i=0; i<w.size(); i++){
        v2[i] = base(w[i] >> 15, w[i] & 32767);
    }
    fft(v1,0);
    fft(v2,0);
    for (int i=0; i<n; i++){
        int j = (i ? (n - i) : i);
        base ans1 = (v1[i] + conj(v1[j])) * base(0.5,0);
        base ans2 = (v1[i] - conj(v1[j])) * base(0,-0.5);
        base ans3 = (v2[i] + conj(v2[j])) * base(0.5,0);
        base ans4 = (v2[i] - conj(v2[j])) * base(0,-0.5);
        r1[i] = (ans1 * ans3) + (ans1 * ans4) * base(0,1);
        r2[i] = (ans2 * ans3) + (ans2 * ans4) * base(0,1);
    }
    fft(r1,1);
    fft(r2,1);
    vector<ll> ret(n);
    for (int i=0; i<n; i++){
        ll av = (ll)round(r1[i].real());
        ll bv = (ll)round(r1[i].imag()) + (ll)round(r2[i].real());
        ll cv = (ll)round(r2[i].imag());
        av %= mod, bv %= mod, cv %= mod;
        ret[i] = (av << 30) + (bv << 15) + cv;
        ret[i] %= mod;
        ret[i] += mod;
        ret[i] %= mod;
    }
    return ret;
}


template<typename T>
struct SegTree{
    int size, start;
    vector<T> arr;
    vector<T> lazy;

    SegTree(int n): size(n) {
        start = 1;
        while (start <= size) start *= 2;
        arr.resize(start+size);
        lazy.resize(start+size);
    }

    void propagate(int node, int ns, int ne){
        if(lazy[node] != 0){
            if(node < start){
                lazy[node*2] ^= 1;
                lazy[node*2+1] ^= 1;

                int left = (lazy[node*2]) ? (ne-ns)/2 - arr[node*2] : arr[node*2];
                int right = (lazy[node*2+1]) ? (ne-ns)/2 - arr[node*2+1] : arr[node*2+1];
                arr[node] = left + right;

            } else {
                arr[node] ^= 1;
            }
            lazy[node] = 0;
        }
    }

    void update(int s, int e) { update(s, e+1, 1, 0, start); }
    void update(int s, int e, int node, int ns, int ne) {
        propagate(node, ns, ne);

        if (e <= ns || ne <= s) return;
        if (s <= ns && ne <= e) {
            lazy[node] ^= 1;
            propagate(node, ns, ne);
            return;
        }
        int mid = (ns+ne)/2;
        update(s, e, node*2, ns, mid);
        update(s, e, node*2+1, mid, ne);
        
        arr[node] = merge(arr[node*2], arr[node*2+1]);
    }

    T query(int s, int e) { return query(s, e+1, 1, 0, start); }
    T query(int s, int e, int node, int ns, int ne){
        propagate(node, ns, ne);
        if (e <= ns || ne <= s) return 0;
        if (s <= ns && ne <= e) return arr[node];
        int mid = (ns+ne)/2;
        return merge(query(s, e, node*2, ns, mid), query(s, e, node*2+1, mid, ne));
    }

    T merge(T l, T r) {
        return l + r;
    }
};


const int SIZE = 100001;
const int MOD = 880803841;


ll power(ll a, ll e) {
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
    return power(x, MOD-2);
}


int n,m,d;

long long fact[SIZE];
long long invf[SIZE];
long long term[SIZE];


void solve() {
    cin >> n >> m >> d;

    vector<ll> v1(term, term+n+1);

    vector<ll> v2(n+1);
    for (ll i=0; i<=n; i++) {
        v2[i] = power(i, (ll)n) * invf[i] % MOD;
    }

    vector<ll> stirling = conv(v1, v2, MOD);

    SegTree<int> xor_st(m+1);

    while (d--) {
        int l, r;
        cin >> l >> r;

        xor_st.update(l, r);
        int k = n - xor_st.query(1, m);
        cout << stirling[k] % MOD << endl;
    }
}

int main() {
    fastio;

    fact[0] = 1;
    for (int i=1; i<SIZE; i++) fact[i] = fact[i-1] * i % MOD;
    invf[SIZE-1] = inv(fact[SIZE-1]);
    for (int i=SIZE-2; i>=0; i--) invf[i] = invf[i+1] * (i+1) % MOD;

    copy(invf, invf+SIZE, term);
    for (int i=1; i<SIZE; i+=2) term[i] = (MOD - term[i]);

    int t; cin >> t;
    while (t--) solve();
}